#include <map>
#include <iostream>
#include <fstream>
#include "Solver.h"
#include "../algorithm/EKAlgoritm.h"


/**
 * PUBLIC FUNCTIONS
 */

Solver::Solver(const std::vector<Flight> &flights, int version) {

    this->flights = flights;
    this->network = Network();
    generateNetwork(version);
}

void Solver::runAlgorithm(string root) {

    ofstream c;
    c.open("com.txt", fstream::in | fstream::out | fstream::app);
    c << this->flights.size() << " - ";


    ofstream csv;
    csv.open ("time.csv", fstream::in | fstream::out | fstream::app);
    csv << this->flights.size() << ";";

    const clock_t begin_time = clock();

    EKAlgoritm algorithm;
    int max = algorithm.EK(this->network);

    csv << float( clock () - begin_time ) /  CLOCKS_PER_SEC << ";";


    generateResult();
    c << getOptim() << endl;
    ofstream res;
    res.open ("Results1.txt", fstream::in | fstream::out | fstream::app);
    res << root << " " << result.size() << endl;
    printResult();
}

void Solver::generateResult() {

    int nFlights = this->flights.size();
    vector<int> connections(nFlights+1,-1);

    for(int i = 1; i <= nFlights; ++i) {
        connections[i] = foundConnection(i,nFlights);
    }


    int n = this->network.getNodes();

    int pos = 0;
    vector<bool> used(n,false);




    for(int i = 1; i <= nFlights; ++i) {

        if(!used[i]) {
            queue<int> travel;
            travel.push(i);

            used[i] = true;
            int aux = connections[i];
            if(aux != 1) {
                while (aux != -1) {
                    travel.push(aux);
                    used[aux] = true;
                    aux = connections[aux];
                }
            }
           result.push(travel);
        }
        ++pos;
    }
    // Ir nodo a nodo y ver quien esta conectado con quien e ir haciendo cadenas
}

/**
 * PRIVATE FUNCTIONS
 */
void Solver::generateNetwork(int version) {

    int n = this->flights.size();
    int size = n*2 + 2;

    this->network.addNodes(size);

    if(version == 0) generateEdgesV1(n,size);
    else generateEdgesV2(n,size);
}

void Solver::generateEdgesV1(int n, int size) {

    map<int,vector<int>> listAdj;
    for(int i = 1; i <= n; ++i) {

        bool isPosible = true;
        int j = 1;
        while(isPosible and j <= i) {  //Mentres no hagi trobat cap avio que no arribi a agafar-lo

            if(canConnect(i,j)){
                network.addEdge(i,j+n,1);
            }
            --j;
        }
        network.addEdge(0,i,1);    //Source
        network.addEdge(i+n,size-1,1); //Sink
    }
}

void Solver::generateEdgesV2(int n, int size) {

}

bool Solver::canConnect(int i, int j) {

    bool samePlace = (flights[i].getDestination() == flights[j].getOrigin());
    bool goodTime = (flights[i].getHF()+15 < flights[j].getHI());

    if(samePlace and goodTime) return true;
    return false;
}

int Solver::foundConnection(int i, int nFlights) {

    int j = 1;
    while(j <= nFlights) {

        if(network.getFlowValue(i,j+nFlights)==1)
            return j;
        ++j;
    }

    return -1;
}

void Solver::printResult() {

    // TIME FILE ------------------------------------------

    ofstream csv;
    csv.open ("time.csv", fstream::in | fstream::out | fstream::app);
    csv << result.size() << endl;



    // RESULTS FILE ---------------------------------------

    ofstream res;
    res.open ("results.txt", fstream::in | fstream::out | fstream::app);
    res << result.size() << endl;

    while (!result.empty()){
        queue<int> list = result.front();
        result.pop();

        while(!list.empty()){

            res << list.front() << " ";
            list.pop();
        }
        res << endl;
    }
    res << endl;
}

int Solver::getOptim() {

    int i = 0;
    queue< queue<int> > Q = this->result;


    while(!Q.empty()) {
        queue<int> aux = Q.front();
        Q.pop();
        while(!aux.empty()) {
            aux.pop();
            ++i;
        }
    }
    return i;
}


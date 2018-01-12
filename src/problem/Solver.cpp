#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Solver.h"
#include "../algorithm/EKAlgoritm.h"


/**
 * PUBLIC FUNCTIONS
 */

Solver::Solver(const std::vector<Flight> &flights, int version) {

    this->flights = flights;
    this->network = Network();
    this->nPilots = 0;
    generateNetwork(version);
}

void Solver::runAlgorithm(string root, int version) {

    ofstream c,csv;
    c.open("com.txt", fstream::in | fstream::out | fstream::app);
    c << this->flights.size() << " - ";

    // PROBLEMA -------------------------------------------
    EKAlgoritm algorithm;
    int max = algorithm.EK(this->network);

    if(version==0) generateResult1();
    else generateResult2();
    //-----------------------------------------------------

    ofstream res;
    res.open ("Results1.txt", fstream::in | fstream::out | fstream::app);
    res << root << " " << result.size() << endl;

    c << getOptim() << endl;

    this->nPilots =  result.size();

    printResult();
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

    for(int i = 0; i < n; ++i) {

        int j = 0;
        while(j < n) {  //Mentres no hagi trobat cap avio que no arribi a agafar-lo

            if(canConnect(i,j)){
                network.addEdge(i+1,j+n+1,1);
            }
            ++j;
        }
        network.addEdge(0,i+1,1);    //Source
        network.addEdge(i+n+1,size-1,1); //Sink
    }

}

void Solver::generateEdgesV2(int n, int size) {
        generateEdgesV1(n,size);

        for(int i = n+1; i <= 2*n; ++i) {

            if(network.getNNodes(i-n) > 1) {

                vector<int> out;
                for(int j = 1; j <= n; ++j){
                    if(network.getCapValue(j,i) == 1) {
                        out.push_back(j);
                    }
                }

                if(out.size() > 1) {
                    for(int x = 0; x < network.getNNodes(i-n); ++x) {
                        for(int y = 0; y < out.size(); ++y) {
                            pair<int,int> aux(out[y], network.getNode(i-n,x));
                            this->connectedBy[aux] = i-n;
                            this->network.addEdge(out[y],network.getNode(i-n,x),1);
                        }
                    }
                }
            }

        }
}


void Solver::generateResult1() {

    int n = this->network.getNodes();
    int pos = 0;

    int nFlights = this->flights.size();
    vector<int> connections(nFlights+1,-1);

    for(int i = 1; i <= nFlights; ++i)
        connections[i] = foundConnection(i,nFlights);


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

void Solver::generateResult2() {

    int n = this->network.getNodes();
    int pos = 0;

    int nFlights = this->flights.size();

    vector<vector<int> > connections(nFlights+1,vector<int>(1,-1));


    for(int i = 1; i <= nFlights; ++i) {

        int x = foundConnection(i,nFlights);
        vector<int> intersection = network.adjIntersection(i,x,nFlights);
        if(intersection.empty()) connections[i][0] = x;
        else {
            int aux = intersection[0];
            connections[i][0] = aux;
            connections[i].push_back(x);
        }


    }



    vector<bool> used(n,false);
    for(int i = 1; i <= nFlights; ++i) {

        if(!used[i]) {
            queue<int> travel;
            travel.push(i);

            int aux;
            if (connections[i].size() == 1) aux = connections[i][0];
            else {
                travel.push(connections[i][0]);
                aux = connections[i][1];
            }
            if(aux != 1) {
                while (aux != -1) {
                    travel.push(aux);
                    used[aux] = true;
                    if (connections[i].size() == 1) aux = connections[i][0];
                    else {
                        travel.push(connections[i][0]);
                        aux = connections[i][1];
                    }
                }
            }
            result.push(travel);
        }
        ++pos;
    }

}


//CONSULTS -------------------------------------------------


bool Solver::canConnect(int i, int j) {


    bool samePlace = (flights[i].getDestination() == flights[j].getOrigin());
    bool goodTime = (flights[i].getHF() + 15 <= flights[j].getHI());

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

int Solver::getNPilots() {
    return this->nPilots;
}

void Solver::printResult() {

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



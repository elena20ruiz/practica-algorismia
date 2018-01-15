#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include "SolverBi.h"
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

    /*
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

        */


    generateEdgesV1(n,size);
    queue<int> queue;
    // por cada nodo
    for(int i = n+1; i < 2*n; ++i){
        // ver numero de nodos entrada
        for(int j = 1; j <= n; ++j){
            if(network.getCapValue(j,i)) {
                int x = j;
                queue.push(x);
            }
        }


            int i2 = i - n;
            // recorremos nodos salida (lista adyacencias de nodo i)
            while(!queue.empty()) {
                int aux2 = queue.front();
                queue.pop();
                for(int j = 0; j < network.adjMatrix[i2].size(); ++j){
                    int v = network.getNode(i,j);
                    network.addEdge(aux2,v,1);
                }
            }
    }
}

void Solver::generateResult1() {

    int n = this->flights.size();
    vector<int> parent(n,-1);

    for(int i = n+1; i <= 2*n+1; ++i) {
        int j = 1;
        bool trobat = false;
        while(j <=n and !trobat) {
            int x = i-n;
            if(network.getFlowValue(j,i) == 1) {
                trobat = true;

                parent[x] = j;
            }
            ++j;
        }
    }


    //Mirarmos lo que no tienen flow desde source
    for(int i = 1; i <= n; ++i) {

        if(network.getFlowValue(0,i)==0){

            stack<int> S;
            S.push(i);

            int aux = parent[i];
            while( aux != -1) {

                S.push(aux);
                aux = parent[aux];
            }
            result.push(S);
        }

    }
    this->nPilots = result.size();
}

void Solver::generateResult2() {
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
    queue< stack<int> > Q = this->result;


    while(!Q.empty()) {
        stack<int> aux = Q.front();
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

//OUTPUT -------------------------------------------------

void Solver::printResult() {

    // RESULTS FILE ---------------------------------------

    ofstream res;
    res.open ("results.txt", fstream::in | fstream::out | fstream::app);
    res << this->nPilots << endl;


    while (!result.empty()){
        stack<int> list = result.front();

        result.pop();

        while(!list.empty()){

            res << list.top() << " ";
            list.pop();

        }
        res << endl;
    }
    res << endl;
}



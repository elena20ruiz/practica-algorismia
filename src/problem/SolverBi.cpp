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

SolverBi::SolverBi(const std::vector<Flight> &flights, int version) {
    this->flights = flights;
    this->network = Network();
    this->nPilots = 0;
    generateNetwork(version);
}

void SolverBi::runAlgorithm(string root, int version) {

    ofstream c,csv;
    c.open("com.txt", fstream::in | fstream::out | fstream::app);
    c << this->flights.size() << " - ";


    // PROBLEMA -------------------------------------------
    EKAlgoritm algorithm;
    int max = algorithm.EK(this->network);

    if(version == 2) generateResult1();
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

void SolverBi::generateNetwork(int version) {

    int n = this->flights.size();
    int size = n*2 + 2;

    this->network.addNodes(size);

    if(version == 2) generateEdgesV1(n,size);
    else generateEdgesV2(n,size);
}

void SolverBi::generateEdgesV1(int n, int size) {

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

void SolverBi::generateEdgesV2(int n, int size) {

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
                for(int j = 0; j < network.getNNodes(i2); ++j){
                    int v = network.getNode(i2,j);
                    network.addEdge(aux2,v,1);
                }
            }
    }
}

void SolverBi::generateResult1() {

    int n = this->flights.size();
    vector<int> parent(n+1,-1);

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

void SolverBi::generateResult2() {
    int n = this->flights.size();
    vector< vector<int> > parent(n+1,vector<int>(1,-1));

    for(int i = n+1; i <= 2*n+1; ++i) {
        int j = 1;
        bool trobat = false;
        while(j <=n and !trobat) {
            int x = i-n;
            if(network.getFlowValue(j,i) == 1) {
                trobat = true;
                if(network.exist(j,i))parent[x][0] = j;
                else{
                    int t = foundConnection(j,x);
                    parent[x][0] = t;
                    parent[x].push_back(j);
                }
            }
            ++j;
        }
    }

    vector<bool> used( 2*n+2,false);
    stack<int> travel;
    for(int i = 1; i <= n; ++i) {

        if(!used[i]) {
            travel = stack<int>();
            travel.push(i);

            int aux;
            if (parent[i].size() == 1) aux = parent[i][0];
            else {
                int x = parent[i][0];
                travel.push(x);
                aux = parent[i][1];
            }
            if(aux != 1) {
                int aux2 = aux;
                while (aux2 != -1) {
                    travel.push(aux2);
                    used[aux2] = true;

                    aux = aux2;
                    if (parent[aux].size() == 1) {
                        aux2 = parent[aux][0];
                    }
                    else {
                        travel.push(parent[aux][0]);
                        aux2 = parent[aux][1];
                    }
                }
            }
            result.push(travel);
        }
    }
    /*
    //Mirarmos lo que no tienen flow desde source
    for(int i = 1; i <= n; ++i) {

        if(network.getFlowValue(0,i)==0){

            stack<int> S;
            S.push(i);

            int aux;
            if(parent[i].size() == 1) aux = parent[i][0];
            while( aux != -1) {

                S.push(aux);
                aux = parent[aux];
            }
            result.push(S);
        }

    }*/
    this->nPilots = result.size();
}


//CONSULTS -------------------------------------------------

bool SolverBi::canConnect(int i, int j) {

    bool samePlace = (flights[i].getDestination() == flights[j].getOrigin());
    bool goodTime = (flights[i].getHF() + 15 <= flights[j].getHI());

    if(samePlace and goodTime) return true;
    return false;
}

int SolverBi::foundConnection(int i, int nFlights) {

    int j = 1;
    while(j <= nFlights) {
        if(network.getFlowValue(i,j+nFlights)==1)
            return j;
        ++j;
    }
    return -1;
}

int SolverBi::getOptim() {

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

int SolverBi::getNPilots() {
    return this->nPilots;
}

//OUTPUT -------------------------------------------------

void SolverBi::printResult() {

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



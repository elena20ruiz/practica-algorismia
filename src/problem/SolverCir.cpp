
#include <climits>
#include "SolverCir.h"
#include "../algorithm/EKAlgoritm.h"

/**
 * PUBLIC FUNCTIONS
 */

SolverCir::SolverCir(const vector<Flight> &flights) {
    this->flights = flights;
    this->network = Network();
    this->nPilots = 0;
    generateNetwork();
}

/**
 * PRIVATE FUNCTIONS
 */

void SolverCir::generateNetwork() {
    int n = this->flights.size();
    int size = n*2 + 2 + 2;

    this->network.setSourceAndSink(size-2,size-1);

    this->network.addNodes(size);
    this->network.generateDemands();
    generateEdgesV1(n,size);
}

void SolverCir::generateEdgesV1(int n, int size) {

    int s = network.getPosSource();
    int t = network.getPosSink();

    for(int i = 1; i <= n; ++i) {

        int j = 1;
        while(j <= n) {  //Mentres no hagi trobat cap avio que no arribi a agafar-lo

            if(canConnect(i,j)){
                network.addEdge(j+n,i,1);
            }
            ++j;
        }
        network.addEdge(0,i,1);       //Pre-source
        network.addEdge(i+n,t-2,1);   //Pre-sink

        network.addEdge(s,i+n,1);     //Source
        network.addEdge(i,t,1);       //Sink
    }
    // EXTRA
    network.addEdge(0,t-2,1);
    network.addEdge(0,s,1);
    network.addEdge(t-2,t,1);
}

bool SolverCir::canConnect(int i, int j) {

    bool samePlace = (flights[i-1].getDestination() == flights[j-1].getOrigin());
    bool goodTime = (flights[i-1].getHF() + 15 <= flights[j-1].getHI());

    if(samePlace and goodTime) return true;
    return false;
}

int SolverCir::getNPilots() {
    return this->nPilots;
}


void SolverCir::runAlgorithm(string root) {

    // PROBLEMA -------------------------------------------
    network.setK(flights.size()/2);
    EKAlgoritm algorithm;
    int max, aux;
    max = INT_MAX;
    bool menor = true;
    int k = flights.size()/2;
    Network network1;
    while(menor) {
        this->network.setK(k);
        aux = algorithm.EK(this->network);
        if(aux == 0) menor = false;
        else if(aux < max) {
            network1 = this->network;
            this->network.resetFlow();
           // network1.setK(k);
            k -= k/2;
            max = aux;
        }
        else if(aux > max) {
            network1 = this->network;
            this->network.resetFlow();
          //  network1.setK(k);
            k += k/2;
            max = aux;
        }
        else menor = false;
    }
    this->network = network1;

    this->nPilots = max - flights.size();
    generateResult();
    //-----------------------------------------------------

    ofstream res;
    res.open ("Results1.txt", fstream::in | fstream::out | fstream::app);
    res << root << " " << result.size() << endl;

    printResult();
}

void SolverCir::generateResult() {

    int n = this->flights.size();
    vector<int> parent(n+1,-1);

    for(int i = n+1; i <= 2*n+1; ++i) {
        int j = 1;
        bool trobat = false;
        while(j <=n and !trobat) {
            int x = i-n;
            if(network.getFlowValue(i,j) == 1) {
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

}

void SolverCir::printResult() {

}


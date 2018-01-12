
#include "SolverCir.h"

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
    int size = n*2 + 2;

    this->network.addNodes(size);
    this->network.generateDemands();
    generateEdgesV1(n,size);
}

void SolverCir::generateEdgesV1(int n, int size) {

    for(int i = 0; i < n; ++i) {

        int j = 0;
        while(j < n) {  //Mentres no hagi trobat cap avio que no arribi a agafar-lo

            if(canConnect(i,j)){
                network.addEdge(j+n+1,i+1,1);
            }
            ++j;
        }
        network.addEdge(0,i+1,1);    //Source
        network.addEdge(i+n+1,size-1,1); //Sink
    }

}

bool SolverCir::canConnect(int i, int j) {

    bool samePlace = (flights[i].getDestination() == flights[j].getOrigin());
    bool goodTime = (flights[i].getHF() + 15 <= flights[j].getHI());

    if(samePlace and goodTime) return true;
    return false;
}

int SolverCir::getNPilots() {
    return this->nPilots;
}

#include <map>
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

void Solver::runAlgorithm() {
    EKAlgoritm algorithm;
    int max = algorithm.EK(this->network);
}

void Solver::generateResult() {

    int nFlights = this->flights.size();
    int n = this->network.getNodes();
    vector<bool> nodes_used(nFlights,false);

    vector< vector<int> > pilotTravels;

    bool allAssigned = false;
    for(int i = 0; i < nFlights; ++i) {


        while(!allAssigned) {





        }


    }
    // Ir nodo a nodo y ver quien esta conectado con quien e ir haciendo cadenas
}

/**
 * PRIVATE FUNCTIONS
 */
void Solver::generateNetwork(int version) {

    int n = this->flights.size();
    int size = n*2 + 2;

    // Generar nodos
    vector<int> nodes(size);
    int source = -1;
    int sink = -2;

    network.setIdSink(sink);
    network.setIdSource(source);

    nodes[0] = -1;
    nodes[size-1] = -2;


    // Copiar todos los nodos
    for(int i = 1; i <= n; ++i ) {
        nodes[i] = i-1;
        nodes[i+n] = i-1;
    }

    this->network.addNodes(nodes);

    if(version == 0) generateEdgesV1(n,size);
    else generateEdgesV2(n,size);
}

void Solver::generateEdgesV1(int n, int size) {

    map<int,vector<int>> listAdj;
    for(int i = 0; i < n; ++i) {

        bool isPosible = true;
        int j = n-1;
        while(isPosible and i < j) {  //Mentres no hagi trobat cap avio que no arribi a agafar-lo

            if(canConnect(i,j)){
                network.addEdge(i+1,j+n+1,1);
            }
            --j;
        }
        network.addEdge(0,i+1,1);    //Source
        network.addEdge(i+n+1,size-1,1); //Sink
    }
}

void Solver::generateEdgesV2(int n, int size) {

}

bool Solver::canConnect(int i, int j) {

    bool samePlace = (flights[i].getDestination() == flights[j].getOrigin());
    bool goodTime = (flights[i].getHF()+0.15 <= flights[j].getHI());

    if(samePlace and goodTime) return true;
    return false;
}




#include <map>
#include "Solver.h"
#include "../algorithm/EKAlgoritm.h"

Solver::Solver(const std::vector<Flight> &flights) {
    this->flights = flights;
    generateNetwork();
}

void Solver::solveVersion1() {
    EKAlgoritm algorithm;

    vector<int> result = algorithm.solve( this->network);
}

/**
 * Pre: Flights is before introduced.
 */
void Solver::generateNetwork() {

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

    //Flights
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

bool Solver::canConnect(int i, int j) {
    int endHour = flights[i].getHF();
    int iniHour = flights[j].getHI();
    if( endHour + 0.25 <= iniHour and flights[i].getDestination() == flights[j].getOrigin()) return true;
    return false;
}

int Solver::generatedNodes() {
    return this->network.getNodes();
}

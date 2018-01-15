
#ifndef PRACTICA_SOLVERCIR_H
#define PRACTICA_SOLVERCIR_H


#include <stack>
#include <queue>
#include "../classes/Flight.h"
#include "../classes/Network.h"

class SolverCir {

private:
    Network network;
    std::vector<Flight> flights;
    std::queue< std::stack<int> > result;

    int nPilots;

public:

    void generateNetwork(int version);

    void generateEdgesV1(int n, int size);

};


#endif //PRACTICA_SOLVERCIR_H

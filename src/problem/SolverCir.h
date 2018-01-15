
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

    void generateNetwork();
    void generateEdgesV1(int n, int size);
    bool canConnect(int i, int j);


public:
    SolverCir(const std::vector<Flight> &flights);

    void runAlgorithm(string root);

    int getNPilots();

    void generateResult();

    void printResult();
};


#endif //PRACTICA_SOLVERCIR_H

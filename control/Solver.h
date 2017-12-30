#ifndef PRACTICA_ALGORISMIA_SOLVER_H
#define PRACTICA_ALGORISMIA_SOLVER_H


#include "../classes/problem/Problem.h"
#include "../classes/basics/Network.h"
#include "Algorithm.h"

class Solver {

private:
    Problem problem;
    Network graph;
    Algorithm algorithm;

    void generateNetwork(vector<Transition> &transitions);
    void generateNodes(vector<Transition> &nodes);
    void generateMatrixs(int n);

public:
    Solver(Problem &problem);

    //TODO: Primer algoritmo pedido
    void solveVersion1();

    //TODO: Segundo algoritmo pedido
    void solveVersion2();

    //TODO: Escribir los resultados en los archivos
    void printResult();

    std::vector< std::vector<int> > getFlowMatrix();
    int getNumberNodes();

    Node getSource();


};


#endif //PRACTICA_ALGORISMIA_SOLVER_H

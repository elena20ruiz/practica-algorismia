
#ifndef PRACTICA_SOLVER_H
#define PRACTICA_SOLVER_H


#include "../classes/Network.h"
#include "../classes/Edge.h"

class Solver {

    private:
        Network network = Network(std::vector<Node>(), std::vector<Edge>());

    public:
        Solver(const std::vector<int> &nodes,  const std::vector<Edge> &edges);

        //TODO: Primer algoritmo pedido
        void solveVersion1();

        //TODO: Segundo algoritmo pedido
        void solveVersion2();

        //TODO: Escribir los resultados en los archivos
        void printResult();

};


#endif //PRACTICA_SOLVER_H

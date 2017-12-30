
#ifndef PRACTICA_SOLVER_H
#define PRACTICA_SOLVER_H


#include "../classes/Network.h"
#include "../classes/Edge.h"

class Solver {

    private:
        Network network = Network();

    public:
        Solver(const vector<vector<int> >  &flights, const vector<int> &cities);

        //TODO: Primer algoritmo pedido
        void solveVersion1();

        //TODO: Segundo algoritmo pedido
        void solveVersion2();

        //TODO: Escribir los resultados en los archivos
        void printResult();

};


#endif //PRACTICA_SOLVER_H

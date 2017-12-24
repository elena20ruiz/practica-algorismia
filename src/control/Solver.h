#ifndef PRACTICA_ALGORISMIA_SOLVER_H
#define PRACTICA_ALGORISMIA_SOLVER_H


#include "../classes/Problem.h"

class Solver {

private:
    Problem problem;

public:
    explicit Solver(const Problem &problem);

    //TODO: Primer algoritmo pedido
    void solveVersion1();

    //TODO: Segundo algoritmo pedido
    void solveVersion2();

    //TODO: Escribir los resultados en los archivos
    void printResult();


};


#endif //PRACTICA_ALGORISMIA_SOLVER_H

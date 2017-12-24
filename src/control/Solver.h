#ifndef PRACTICA_ALGORISMIA_SOLVER_H
#define PRACTICA_ALGORISMIA_SOLVER_H


#include "../classes/Problem.h"

class Solver {

private:
    Problem problem;

public:
    explicit Solver(const Problem &problem);

    void solveVersion1();
    void solveVersion2();


};


#endif //PRACTICA_ALGORISMIA_SOLVER_H

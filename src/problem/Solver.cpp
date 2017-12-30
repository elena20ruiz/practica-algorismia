

#include "Solver.h"
#include "../algorithm/EKAlgoritm.h"

Solver::Solver(const vector<vector<int> > &flights, const std::vector<int> &cities) {

    this->network = Network(flights,cities);

}


void Solver::solveVersion1() {
    EKAlgoritm algoritm;

    vector<Edge> result = algoritm.solve(this->network);



}


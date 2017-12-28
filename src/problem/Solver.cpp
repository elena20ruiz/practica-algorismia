

#include "Solver.h"
#include "../algorithm/EKAlgoritm.h"

Solver::Solver(const std::vector<int> &nodes, const std::vector<Edge> &edges) {

    std::vector<Node> airports;

    for(int i = 0; i < nodes.size(); ++i){
        airports.emplace_back(nodes[i]);
    }

    this->network = Network(airports, edges);

}

void Solver::solveVersion1() {
    EKAlgoritm algoritm;

    vector<Edge> result = algoritm.solve(this->network);



}

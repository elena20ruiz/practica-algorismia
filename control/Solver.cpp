#include "Solver.h"


Solver::Solver(Problem &problem){
    this->problem = problem;

    generateNetwork(problem.getTransitions());

}

void Solver::solveVersion1() {







}

void Solver::solveVersion2() {

}

void Solver::printResult() {

}

/**
 * PRIVATE FUNCTIONS
 */

void Solver::generateNetwork(vector<Transition> &transitions) {

    generateNodes(transitions);
    generateMatrixs(static_cast<int>(transitions.size()));

}

void Solver::generateNodes(vector<Transition> &transitions) {

    vector<Node> nodes;

    //Source:
    Node source = Node(0);
    nodes.push_back(source);

    Node aux;
    for(int i = 0; i < transitions.size(); ++i) {
        aux = Node(transitions[i]);
        nodes.emplace_back(aux);
    }
    for (int i = 0; i < transitions.size(); ++i) {
        Pilot pilot = Pilot(i);
        nodes.emplace_back(pilot);
    }
    Node sink = Node(3);
    nodes.push_back(sink);

    this->graph = Network(nodes);

}

void Solver::generateMatrixs(int n) {

    int size = n*2 + 2;

    vector< vector<int> > adjMatrix(size, vector<int>(size));  // Capacity
    vector< vector<int> > flowMatrix(size, vector<int>(size)); // Flow
    vector< vector<int> > resMatrix(size, vector<int>(size));  // C - flow

    //Para cada transition añadir conexion con pilotos i piloto con source
    for(int i = 1; i <= n; ++i) {

        //Source
        adjMatrix[0][i] = 1;
        resMatrix[0][i] = 1;

        for(int j = 1; j <= n; ++j) {

            //Transicion con piloto
            adjMatrix[i][i+j] = 1;
            resMatrix[i][i+j] = 1; //nozezabe

            if(i == 1){ //Para que solo lo escriba una vez
                //Piloto con sink
                adjMatrix[i+j][size-1] = 1;
                resMatrix[i+j][size-1] = 1;  //nozezabe
            }

        }

    }

    this->graph.addAdjMatrix(adjMatrix);
    this->graph.addResMatrix(resMatrix);
    this->graph.addFlowMatrix(flowMatrix);

}

std::vector<std::vector<int> > Solver::getFlowMatrix() {
    return this->graph.getFlowMatrix();
}

int Solver::getNumberNodes() {
    return this->graph.getNumberNodes();
}

Node Solver::getSource() {
    return this->graph.getNode(0);
}


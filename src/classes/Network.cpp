

#include "Network.h"

Network::Network(std::vector<Node> nodes, const std::vector<Edge> &edges) {
    this->edges = edges;
    this->nodes = nodes;

    //Crear source i sinks
    Node sink(-2);
    Node source(-1);

    nodes.insert(nodes.begin(),source);
    nodes.push_back(sink);

    this->adjMatrix = vector< vector<int> > (edges.size());
    this->capMatrix = vector< vector<int> > (edges.size());
    this->flowMatrix = vector< vector<int> > (edges.size());


    //TODO: Llenar las matrices con la información de las aristas.

}

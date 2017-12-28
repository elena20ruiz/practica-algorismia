
#ifndef PRACTICA_NETWORK_H
#define PRACTICA_NETWORK_H

#include <vector>
#include "Node.h"
#include "Edge.h"

using namespace std;

class Network {

private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
    std::vector< std::vector<int> > adjMatrix;
    std::vector< std::vector<int> > capMatrix;
    std::vector< std::vector<int> > flowMatrix;
public:
    Network(std::vector<Node> edges, const std::vector<Edge> &vector);
};

#endif //PRACTICA_NETWORK_H

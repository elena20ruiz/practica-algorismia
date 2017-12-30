
#ifndef PRACTICA_NETWORK_H
#define PRACTICA_NETWORK_H

#include <vector>
#include <map>

#include "Node.h"
#include "Edge.h"

using namespace std;

class Network {

private:
    vector<Node> nodes;
    map<int,int> idNodes;

    vector<Edge> edges;
    map<int,Edge> idEdges;

    vector< map<int,int> > indMatrix;


    vector< vector<bool> > adjMatrix;
    vector< vector<int> > capMatrix;
    vector< vector<int> > flowMatrix;
public:

    Network();
    Network(const vector<vector<int> >  &flights, const vector<int> &cities);

    int existAdjacency(int i,int j);
    int getCapacity(int i, int j);
    int getFlow(int i, int j);
    void setFlow(int i, int j, int f);
    void setCapacity(int i, int j, int f);



};

#endif //PRACTICA_NETWORK_H


#ifndef PRACTICA_NODES_H
#define PRACTICA_NODES_H


#include <vector>
#include "Edge.h"

using namespace std;

class Node {


private:
    int id; //Name of airport
    vector<int> idOutEdges;

    //if id == -1 source
    //if id == -2 sink
public:
    Node(int i);

    void addFligths(const vector<int> &idOutEdges);

    void addFligth(int id);

    int &getId();
};


#endif //PRACTICA_NODES_H

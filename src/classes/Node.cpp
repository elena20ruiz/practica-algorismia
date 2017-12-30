
#include "Node.h"

Node::Node(int i) {
    this->id = i;

}

void Node::addFligths(const vector<int> &idOutEdges) {

    for(int i = 0;  i < idOutEdges.size(); ++i) {
        this->idOutEdges.push_back(idOutEdges[i]);
    }

}

int &Node::getId() {
    return this->id;
}

void Node::addFligth(int id) {
    this->idOutEdges.push_back(id);
}



#include "Network.h"


Network::Network() = default;

void Network::addEdge(int i, int j, int c) {

    this->adjMatrix[i][j] = true;
    this->networkMatrix[i][j].second = c;
}

void Network::addNodes(int n) {
    this->n = n;

    this->adjMatrix = vector< vector<bool> >(n, vector<bool>(n,false));
    this->networkMatrix = vector< vector< pair<int,int> > >(n,vector< pair<int,int> >(n,pair<int,int>(0,0)));

}

int Network::getPosSource(){
    return 0;
}
int Network::getPosSink(){
    return (this->n - 1);
}

int Network::getNodes() {
    return this->n;
}

bool Network::isConnected(int i, int j) {

    return this->adjMatrix[i][j];
}

int Network::getCapValue(int i, int j) {
    return this->networkMatrix[i][j].second;
}

int Network::getFlowValue(int i, int j) {
    return this->networkMatrix[i][j].first;
}

void Network::updateFlowValue(int i, int j, int v) {
    this->networkMatrix[i][j].first += v;
}


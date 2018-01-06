

#include "Network.h"


Network::Network() = default;

void Network::addEdge(int i, int j, int c) {

    this->adjMatrix[i][j] = true;
    this->capMatrix[i][j] = c;
    this->flowMatrix[i][j] = 0;

}

void Network::addNodes(const std::vector<int> &nodes) {
    this->nodes = nodes;
    this->adjMatrix = vector< vector<bool> >(nodes.size(),vector<bool>(nodes.size()));
    this->capMatrix = vector< map<int,int> > (nodes.size());
    this->flowMatrix = vector< map<int,int> > (nodes.size());
}

void Network::setIdSource(int s){
    this->idSource = s;
}

int Network::getIdSource(){
    return this->idSource;
}

int Network::getIdSink(){
    return this->idSink;
}

void Network::setIdSink(int s){
    this->idSink= s;
}

int Network::getNodes() {
    return this->nodes.size();
}

bool Network::isConnected(int i, int j) {
    return this->adjMatrix[i][j];
}

int Network::getCapValue(int i, int j) {
    return this->capMatrix[i][j];
}

int Network::getFlowValue(int i, int j) {
    return this->flowMatrix[i][j];
}

void Network::setFlowValue(int i, int j, int v){
    this->flowMatrix[i][j] = v;
}

void Network::setCapValue(int i, int j, int v){
    this->capMatrix[i][j] = v;
}

void Network::updateFlowValue(int i, int j, int v) {
    this->flowMatrix[i][j] += v;
}


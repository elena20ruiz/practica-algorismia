
#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include "Network.h"

Network::Network() = default;

void Network::addEdge(int i, int j, int c) {

    this->adjMatrix[i].push_back(j);
    this->networkMatrix[i][j].second = c;
}

void Network::addNodes(int n) {
    this->n = n;

    this->adjMatrix = vector< vector<int> >(n);
    this->networkMatrix = vector< vector< pair<int,int> > >(n,vector< pair<int,int> >(n,pair<int,int>(0,0)));

}


// SETTERS AND GETTERS ---------------------------------------------
int Network::getNodes() {
    return this->n;
}

int Network::getNNodes(int i) {
    return this->adjMatrix[i].size();
}

int Network::getNode(int i, int j) {
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

bool Network::exist(int i, int j) {
    int k = 0;
    bool trobat = false;
    int aux;
    while(!trobat and k < adjMatrix[i].size()) {
        aux = adjMatrix[i][k];
        if (aux == j) trobat = true;
        ++k;
    }
    return false;
}

vector<int> Network::adjIntersection(int i, int j, int nF) {


    if(adjMatrix[i].size()==0) return vector<int>();

    vector<int> v3;

    for(int u = 0; u < adjMatrix[i].size();++u) {
        int aux = adjMatrix[i][u] - nF;
        if (!adjMatrix[aux].empty()) {
            int v = 0;
            int size = adjMatrix[aux].size();
            bool trobat = false;
            int aux2;
            while(v < size and !trobat){
                aux2 = adjMatrix[aux][v];
                if(aux2 - nF == j) {
                    trobat = true;
                    v3.push_back(aux);
                }
                ++v;
            }
        }
    }

    return v3;
}

// OUTPUT--------------------------------------------------------
void Network::printRes() {

    for(int i = 0; i < adjMatrix.size(); ++i) {
        cout << i << ":  ";
        for(int j = 0; j < adjMatrix.size(); ++j) {

            if(adjMatrix[i][j]) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < networkMatrix.size(); ++i) {
        cout << i << ":  ";
        for(int j = 0; j < networkMatrix.size(); ++j) {

            cout << networkMatrix[i][j].first << " ";
        }
        cout << endl;
    }
}

void Network::generateDemands() {

}

int Network::getPosSource() {
    return this->source;
}

int Network::getPosSink() {
    return this->sink;
}

void Network::setSourceAndSink(int i, int j) {
    this->source = i;
    this->sink = j;

}

void Network::setK(int i) {

     this->networkMatrix[sink-1][0].second = i;
     this->networkMatrix[sink-2][sink].second = i;

}

void Network::resetFlow() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            this->networkMatrix[i][j].first= 0;
        }
    }
}

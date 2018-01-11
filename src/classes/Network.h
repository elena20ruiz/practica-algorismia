
#ifndef PRACTICA_NETWORK_H
#define PRACTICA_NETWORK_H

#include <vector>
#include <map>
#include <iostream>
#include <fstream>


using namespace std;

class Network {

private:
    int n;

    std::vector< std::vector<bool> > adjMatrix;
    std::vector< std::vector< pair<int,int> >  > networkMatrix;

public:
    Network();

    void addNodes(int n);
    void addEdge(int i, int j, int c);
    
    void printRes();
    int getPosSource();
    int getPosSink();

    int getNodes();

    bool isConnected(int i, int j);
    int getCapValue(int i, int j);
    int getFlowValue(int i, int j);

    void updateFlowValue(int i, int j, int v);

};

#endif //PRACTICA_NETWORK_H

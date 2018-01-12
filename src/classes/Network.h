
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
    std::vector< std::vector<int> > adjMatrix;
    std::vector< std::vector< pair<int,int> >  > networkMatrix;

    // FOR CIRCULATION PROBLEM
    std::vector<int> nodes; //position i contains it demands

public:
    Network();

    void addNodes(int n);
    void addEdge(int i, int j, int c);
    
    void printRes();
    int getPosSource();
    int getPosSink();

    int getNodes();
    int getNNodes(int i);
    int getNode(int i, int j);
    int getCapValue(int i, int j);
    int getFlowValue(int i, int j);

    void updateFlowValue(int i, int j, int v);

    vector<int> adjIntersection(int i, int j, int nF);

    bool exist(int i, int j);

    void generateDemands();
};

#endif //PRACTICA_NETWORK_H

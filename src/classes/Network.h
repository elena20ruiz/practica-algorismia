
#ifndef PRACTICA_NETWORK_H
#define PRACTICA_NETWORK_H

#include <vector>
#include <map>


using namespace std;

class Network {

private:
    std::vector<int> nodes;

    std::vector< std::vector<bool> > adjMatrix;
    std::vector< std::vector<int>  > capMatrix;
    std::vector< std::vector<int>  > flowMatrix;

    int idSource;
    int idSink;

public:
    Network();

    void addNodes(const std::vector<int> &nodes);
    void addEdge(int i, int j, int c);

    void setIdSource(int s);
    void setIdSink(int s);

    int getPosSource();
    int getPosSink();

    int getNodes();

    bool isConnected(int i, int j);
    int getCapValue(int i, int j);
    int getFlowValue(int i, int j);

    void updateFlowValue(int i, int j, int v);

};

#endif //PRACTICA_NETWORK_H

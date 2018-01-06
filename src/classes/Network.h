
#ifndef PRACTICA_NETWORK_H
#define PRACTICA_NETWORK_H

#include <vector>
#include <map>


using namespace std;

class Network {

private:
    std::vector<int> nodes;

    std::vector< std::vector<bool> > adjMatrix;
    std::vector< std::map<int,int> > capMatrix;
    std::vector< std::map<int,int> > flowMatrix;

    int idSource;
    int idSink;

public:
    Network();

    void addNodes(const std::vector<int> &nodes);
    void addEdge(int i, int j, int c);

    void setIdSource(int s);
    void setIdSink(int s);

    int getIdSource();
    int getIdSink();

    int getNodes();


    bool isConnected(int i, int j);
    int getCapValue(int i, int j);
    int getFlowValue(int i, int j);

    void setCapValue(int i, int j, int v);
    void setFlowValue(int i, int j, int v);
    void updateFlowValue(int i, int j, int v);

};

#endif //PRACTICA_NETWORK_H

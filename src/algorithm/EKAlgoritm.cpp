#include <limits>
#include "EKAlgoritm.h"

EKAlgoritm::EKAlgoritm() = default;

int EKAlgoritm::EK(Network &network){



    int n = network.getNodes();
    int s = 0;
    int t = n-1;

    int maxFlow = 0;
    int flow = 0;

    while(true) {
        pair<int,int> pair_aux(-1,0);
        vector<pair<int,int> > P(n,pair_aux);
        P[s].first = 0; // Source
        P[s].second = 99999999;

        queue<int> Q;
        Q.push(s);
        flow = BFS(network,P,Q);

        if(flow == 0) break;
        maxFlow += flow;
    }
    return maxFlow;
}

int EKAlgoritm::BFS(Network &network, vector<pair<int, int>> &P,
                    std::queue<int> &Q) {
    int u;
    int t = network.getNodes()-1;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();

        for(int i = 0; i < network.getNodes();++i) {
            if(network.isConnected(u,i)) {

                int cap = network.getCapValue(u,i);
                int flow = network.getFlowValue(u,i);
                if(cap - flow> 0 and P[i].first == -1) {
                    P[i].first = u;
                    P[i].second = P[u].second; // The minimum
                    if((cap-flow) < P[u].second) P[i].second = (cap-flow);

                    if(i != t) Q.push(i);
                    else {

                        while( P[i].first != i) {
                            u = P[i].first;
                            network.updateFlowValue(u,i,P[t].second);
                            network.updateFlowValue(i,u,-P[t].second);
                            i = u;
                        }

                    }
                }
            }
        }

    }

    return 0;
}


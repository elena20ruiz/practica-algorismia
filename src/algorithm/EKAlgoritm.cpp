#include <limits>
#include <climits>
#include "EKAlgoritm.h"

EKAlgoritm::EKAlgoritm() = default;

int EKAlgoritm::EK(Network &network){

    int n = network.getNodes();
    int s = 0;
    int t = n-1;

    int maxFlow = 0;
    int flow = 0;

    while(true) {

        vector< int> P(n,-1);

        P[s] = s;
        flow = BFS(network,P);

        if(flow == 0) break;
        maxFlow += flow;

        int v = t;
        while(P[v] != v) {
            int u = P[v];
            network.updateFlowValue(u,v,flow);
            network.updateFlowValue(v,u,-flow);
            v = u;
        }

    }
    return maxFlow;
}

int EKAlgoritm::BFS(Network &network, vector<int> &P) {

    int n = network.getNodes();
    int t = n-1;
    int s = 0;
    vector<int> M = vector<int>(n);
    M[0] = INT_MAX;


    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for(int v = 0; v < n; ++v) {
            int c = network.getCapValue(u,v);
            int f = network.getFlowValue(u,v);

            if( ((c-f) >0) && P[v] == -1){

                P[v] = u;
                M[v] = min(M[u], c-f);

                if(v!=t) Q.push(v);
                else return M[t];
            }

        }
    }

    return 0;
}




#include <limits>
#include <queue>
#include "EKAlgoritm.h"

EKAlgoritm::EKAlgoritm() = default;

vector<int> EKAlgoritm::solve(Network n) {

    int size = n.getNodes();
    int source = n.getIdSource();
    int sink = n.getIdSink();
    while(true) {
        vector<int> path(size,-1);
        vector<int> capPath(size,numeric_limits<int>::infinity());
        path[source] = source;
        capPath[source] = numeric_limits<int>::infinity();

        std::queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for(int i = 0; i < size; ++i) {
                if(n.isConnected(i,u)) {
                    // There is available capacity,
                    // and v is not seen before in search

                    int dif = n.getCapValue(u,i) - n.getFlowValue(u,i);

                    bool check = dif > 0 && path[i] == -1;
                    if(check && correctRequisites()) {
                        path[i] = u;
                        capPath[i] = min(capPath[u], dif);
                        if(i != sink) {
                            q.push(i);
                        }
                        else { //Backtrack
                            while (path[i] != i) {
                                u = path[i];
                                n.updateFlowValue(u,i,capPath[sink]);
                                n.updateFlowValue(i,u,-capPath[sink]);
                                i = u;
                            }
                            break;
                        }
                    }
                }
            }
        }
        if (path[sink] == -1) { // We did not find a path to t
            return path;
        }

    }


}


//TODO
bool EKAlgoritm::correctRequisites() {
    return true;
}


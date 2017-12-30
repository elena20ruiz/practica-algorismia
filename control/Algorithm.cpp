#include "Algorithm.h"
#include "../classes/basics/Node.h"
#include <array>
#include <limits>
#include <queue>

matrix Algorithm::EdmondsKarp(matrix &E, matrix &C, int s, int t) {

    int n = C.size();
    int flow = 0;
    matrix flowMatrix(n,vector<int>(n,0));
    while(true) {

        vector<int> P(n,-1);
        vector<int> M(n,0);

        P[s] = -2;
        M[s] = numeric_limits<int>::infinity();
        queue Q;
        Q.push(s);
        pair<int, vector<int> > result = BFSEK(E,C,s,t,flowMatrix, P, M, Q);

        if(result.first == 0) break;
        flow += result.first;

        int v = t;
        int u;
        while (v != s){

            u = P[v];
            flowMatrix[u][v] += result.first;
            flowMatrix[v][u] -= result.first;

            v = u;
        }
    }
}

pair<int, std::vector<int> > Algorithm::BFSEK(matrix &E,
                                              matrix &C,
                                            int source, int sink,
                                            matrix &flowMatrix,
                                            vector<int> &P,
                                            vector<int> &M,
                                            std::queue<int> &Q) {

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < E.size(); ++i) {
            if (E[u][i]) {
                if (C[u][i] - flowMatrix[u][i] > 0 && P[i] == -1) {
                    P[i] = u;
                    M[i] = min(M[u], C[u][i] - flowMatrix[u][i]);
                }
            }
            if(i != sink) Q.push(i);
            else return pair<int ,vector<int> >(M[sink],P);
        }
        return pair<int ,vector<int> >(0,P);
    }
}






#ifndef PRACTICA_EKALGORITM_H
#define PRACTICA_EKALGORITM_H

#include <vector>
#include <queue>
#include "../classes/Network.h"

using namespace std;

class EKAlgoritm {
public:

    EKAlgoritm();


    int EK(Network &network);

    int BFS(Network &network, vector<pair<int, int>> &P, std::queue<int> &Q);
};

#endif //PRACTICA_EKALGORITM_H

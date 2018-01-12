
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

    int BFS(Network &network, vector<int> &P);
};

#endif //PRACTICA_EKALGORITM_H
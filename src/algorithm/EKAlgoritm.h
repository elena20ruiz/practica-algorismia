
#ifndef PRACTICA_EKALGORITM_H
#define PRACTICA_EKALGORITM_H

#include <vector>
#include "../classes/Edge.h"
#include "../classes/Network.h"

using namespace std;

class EKAlgoritm {
public:

    EKAlgoritm();

    std::vector<Edge> solve(Network &network);
};

#endif //PRACTICA_EKALGORITM_H

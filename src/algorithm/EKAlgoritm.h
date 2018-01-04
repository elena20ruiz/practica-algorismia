
#ifndef PRACTICA_EKALGORITM_H
#define PRACTICA_EKALGORITM_H

#include <vector>
#include "../classes/Network.h"

using namespace std;

class EKAlgoritm {
public:

    EKAlgoritm();

    std::vector< int> solve(Network n);

    bool correctRequisites();
};

#endif //PRACTICA_EKALGORITM_H

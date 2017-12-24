
#ifndef PRACTICA_ALGORISMIA_PROBLEM_H
#define PRACTICA_ALGORISMIA_PROBLEM_H


#include <vector>
#include "Transition.h"
#include "Pilot.h"

using namespace std;

class Problem {
private:
    vector<Transition> transitions;
    vector<Pilot> pilots;

public:
    Problem(const vector<Transition> &transitions);

};

#endif //PRACTICA_ALGORISMIA_PROBLEM_H

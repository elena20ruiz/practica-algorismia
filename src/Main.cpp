#include <iostream>
#include <fstream>
#include <vector>
#include "classes/Transition.h"
#include "classes/Problem.h"
#include "control/Solver.h"

using namespace std;

int main() {

    ifstream file("../Benchmark/instance_100_2_1.air");
    if(file.good())
    {
        vector<Transition> transitions;
        int origen, destination, hI, hF;

        while(file >> origen >> destination >> hI >> hF) {

            Transition transition(origen,destination,hI,hF);
            transitions.push_back(transition);

        }

        Problem problem(transitions);
        Solver solver(problem);
    }
    else cout << "BAD" << endl;


}



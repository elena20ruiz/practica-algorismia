#include <iostream>
#include <fstream>
#include <vector>
#include "classes/Transition.h"
#include "classes/Problem.h"

using namespace std;

int main() {

    ifstream file("input.txt");
    if(file.is_open())
    {
        vector<Transition> transitions;
        int origen, destination, hI, hF;

        while(file >> origen >> destination >> hI >> hF) {

            Transition transition(origen,destination,hI,hF);
            transitions.push_back(transition);

        }

        Problem problem(transitions);

    }


}



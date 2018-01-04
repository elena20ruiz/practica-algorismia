#include <iostream>
#include <fstream>
#include <vector>
#include "src/problem/Solver.h"
#include "src/classes/Flight.h"

void noDuplicated(vector<int> vector);

void uniqueNodes(vector<int> vector);

using namespace std;

int main() {

    ifstream file("../Benchmark/instance_100_2_1.air");
    if(file.good())
    {
        vector<Flight> flights;
        string o;
        int origen, destination, hI, hF;

        while(file >> o >> destination >> hI >> hF) {

            origen = std::stoi(o);


            Flight transition(origen,destination,hI,hF);
            //flights.push_back(transition);

        }



        Flight transition(0,1,0,3);
        flights.push_back(transition);
        Flight transition2(1,2,4,5);
        flights.push_back(transition2);
        Flight transition3(1,2,5,6);
        flights.push_back(transition3);

        Solver solver(flights);
        solver.solveVersion1();

    }
    else cout << "BAD" << endl;
}



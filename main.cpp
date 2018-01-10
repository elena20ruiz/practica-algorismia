#include <iostream>
#include <fstream>
#include <vector>
#include "src/problem/Solver.h"
#include <string.h>

void readFile(string basic_string);

using namespace std;

int main() {


/*
    int n = 1;
    int instance = 1;
    string root = "../Benchmark/instance_100_";
    while(instance < 30) {
        while (n < 10) {

            string ins = to_string(instance);
            string strn = to_string(n);
            string file = root + ins + string("_") + strn + string(".air");

            readFile(file,0);
            ++n;
        }
        ++instance;
    }
*/


    vector<Flight> flights;
    Flight transition(0,1,0,3);
    flights.push_back(transition);
    Flight transition2(1,2,4,5);
    flights.push_back(transition2);
    Flight transition3(1,2,5,6);
    flights.push_back(transition3);

    Solver solver(flights,0);
    solver.runAlgorithm();
}

void readFile(string root, int version) {

    ifstream file(root);
    if(file.good()) {
        vector<Flight> flights;
        string o;
        int origen, destination, hI, hF;

        while (file >> o >> destination >> hI >> hF) {

            origen = std::stoi(o);

            Flight transition(origen, destination, hI, hF);
            flights.push_back(transition);

        }

        Solver solver(flights,version);
        solver.runAlgorithm();
    }
    else cout << "BAD" << endl;

}



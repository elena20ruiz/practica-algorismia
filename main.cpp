#include <iostream>
#include <fstream>
#include <vector>
#include "src/problem/Solver.h"
#include <string.h>

void readFile(string root, int version, string id);

using namespace std;


int main() {

    vector<Flight> flights;

    int n;
    int instance = 2;
    string root = "instance_100_";
    while(instance <= 30) {
        n = 1;
        while (n <= 10) {

            string ins = to_string(instance);
            string strn = to_string(n);
            string file = "Benchmark/" + root + ins + string("_") + strn + string(".air");

            //file = "input.txt";
            readFile(file,0,ins + "_" + strn);
            ++n;
        }
        ++instance;
    }
    /*

    Flight transition(0,1,0,3);
    flights.push_back(transition);
    Flight transition2(1,2,4,5);
    flights.push_back(transition2);
    Flight transition3(1,2,5,6);
    flights.push_back(transition3);

    Solver solver(flights,0);
    solver.runAlgorithm();

*/
}


void readFile(string root, int version, string id_exp) {

    ofstream csv;
    csv.open ("time.csv", fstream::in | fstream::out | fstream::app);
    
    // Start cols
    csv << "id_exp" << "n_flights";
    
    
    
    csv << id_exp << ";";

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

        Solver solver(flights,0);
        solver.runAlgorithm(root);
    }
    else cout << "BAD" << endl;

}


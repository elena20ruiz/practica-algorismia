#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "classes/Problem.h"
#include "src/problem/Solver.h"
#include "src/classes/Edge.h"

void noDuplicated(vector<int> vector);

void uniqueNodes(vector<int> vector);

using namespace std;

int main() {

    ifstream file("../Benchmark/instance_100_2_1.air");
    if(file.good())
    {
        vector<Edge> edges;
        vector<int> cities;
        int origen, destination, hI, hF;

        while(file >> origen >> destination >> hI >> hF) {

            Edge edge(origen,destination,hI,hF);
            edges.push_back(edge);

            cities.push_back(origen);
            cities.push_back(destination);

        }

        uniqueNodes(cities);
        Solver solver(cities,edges);
    }
    else cout << "BAD" << endl;


}

void uniqueNodes(std::vector<int> &vector){

    std::vector<int>::iterator it;
    it = std::unique (vector.begin(), vector.end());
    vector.resize( std::distance(vector.begin(),it) );

}



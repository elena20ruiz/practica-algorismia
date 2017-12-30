#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "problem/Solver.h"

using namespace std;


void deleteDuplicatedCities(std::vector<int> &vector){

    std::vector<int>::iterator it;
    it = std::unique (vector.begin(), vector.end());
    vector.resize( std::distance(vector.begin(),it) );

}


int main() {

    ifstream file("../Benchmark/instance_100_2_1.air");
    if(file.good())
    {
        vector<vector<int> > flights;
        vector<int> cities;
        int origen, destino, hI, hF;

        while(file >> origen >> destino>> hI >> hF) {

            flights.emplace_back({origen,destino,hI,hF});

            cities.push_back(origen);
            cities.push_back(destino);

        }

        deleteDuplicatedCities(cities);
        Solver solver(flights,cities);
    }
    else cout << "BAD" << endl;


}





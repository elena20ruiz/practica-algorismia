
#ifndef PRACTICA_SOLVER_H
#define PRACTICA_SOLVER_H


#include <queue>
#include "../classes/Network.h"
#include "../classes/Flight.h"

class Solver {

    private:
        Network network;
        std::vector<Flight> flights;
        std::queue< queue<int> > result;
        std::map< pair<int,int>, int > connectedBy;

        int nPilots;

        void generateNetwork(int version);
        void generateEdgesV1(int n, int size);
        void generateEdgesV2(int n, int size);
        bool canConnect(int i, int j);
        int foundConnection(int i, int nFlights);
        void printResult();
        void generateResult1();
        void generateResult2();
        int getOptim();


    public:
        Solver(const std::vector<Flight> &flights, int version);

        void runAlgorithm(string root,int version);

        int getNPilots();


    vector<int> hasMoreThanOneEdge();
};


#endif //PRACTICA_SOLVER_H

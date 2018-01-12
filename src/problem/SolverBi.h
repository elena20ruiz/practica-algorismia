
#ifndef PRACTICA_SOLVER_H
#define PRACTICA_SOLVER_H


#include <queue>
#include <stack>
#include "../classes/Network.h"
#include "../classes/Flight.h"

class SolverBi {

    private:
        Network network;
        std::vector<Flight> flights;
        std::queue< std::stack<int> > result;

        // FOR VERSION 2
        std::map< pair<int,int>, int > connectedBy;

        int nPilots;

        void generateNetwork(int version);

        void generateEdgesV1(int n, int size);
        void generateEdgesV2(int n, int size);

        void generateResult1();
        void generateResult2();

        bool canConnect(int i, int j);
        int foundConnection(int i, int nFlights);
        void printResult();


        int getOptim();

        vector<int> hasMoreThanOneEdge();


    public:
        SolverBi(const std::vector<Flight> &flights, int version);

        void runAlgorithm(string root,int version);

        int getNPilots();



};


#endif //PRACTICA_SOLVER_H

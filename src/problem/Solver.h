
#ifndef PRACTICA_SOLVER_H
#define PRACTICA_SOLVER_H


#include "../classes/Network.h"
#include "../classes/Flight.h"

class Solver {

    private:
        Network network;
        std::vector<Flight> flights;

        void generateNetwork(int version);
        void generateEdgesV1(int n, int size);
        void generateEdgesV2(int n, int size);
        bool canConnect(int i, int j);


    public:
        Solver(const std::vector<Flight> &flights, int version);

        void runAlgorithm();
        void generateResult();

    void interpretateOutput();
};


#endif //PRACTICA_SOLVER_H

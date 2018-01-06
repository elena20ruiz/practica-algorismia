
#ifndef PRACTICA_SOLVER_H
#define PRACTICA_SOLVER_H


#include "../classes/Network.h"
#include "../classes/Flight.h"

class Solver {

    private:
        Network network;
        std::vector<Flight> flights;

        void generateNetwork();
        bool canConnect(int i, int j);

    public:
        Solver(const std::vector<Flight> &flights);

        void solveVersion1();
        void solveVersion2();

        void printResult();
};


#endif //PRACTICA_SOLVER_H

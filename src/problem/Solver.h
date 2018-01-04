
#ifndef PRACTICA_SOLVER_H
#define PRACTICA_SOLVER_H


#include "../classes/Network.h"
#include "../classes/Flight.h"

class Solver {

    private:
        Network network = Network();
        std::vector<Flight> flights;

    public:
        Solver(const std::vector<Flight> &flights);


        void generateNetwork();

        //TODO: Primer algoritmo pedido
        void solveVersion1();

        //TODO: Segundo algoritmo pedido
        void solveVersion2();

        //TODO: Escribir los resultados en los archivos
        void printResult();


    int generatedNodes();

    bool canConnect(int i, int j);
};


#endif //PRACTICA_SOLVER_H

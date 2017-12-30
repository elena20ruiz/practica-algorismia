//
// Created by elenaruiz on 24/12/17.
//

#ifndef PRACTICA_ALGORISMIA_ALGORITHMVERSION1_H
#define PRACTICA_ALGORISMIA_ALGORITHMVERSION1_H

#include <vector>
#include <iostream>
#include <queue>
#include "Solver.h"
#include "../classes/basics/Node.h"


typedef std::vector< std::vector<int> > matrix;

class Algorithm {


private:



public:

    matrix EdmondsKarp(matrix &E, matrix &C, int s, int t);

    pair<int, std::vector<int> > BFSEK( matrix &E,
                                        matrix &C,
                                        int source,
                                        int sink,
                                        matrix &flowMatrix,
                                        vector<int> &P,
                                        vector<int> &M,
                                        std::queue<int> &Q);
};


#endif //PRACTICA_ALGORISMIA_ALGORITHMVERSION1_H

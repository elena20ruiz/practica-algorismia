//
// Created by elenaruiz on 3/01/18.
//

#ifndef PRACTICA_TRANSITION_H
#define PRACTICA_TRANSITION_H


class Flight {

private:
    int origin;
    int destination;
    int hI;
    int hF;

public:

    Flight(int origin, int destination, int hI, int hF);

    int getOrigin() const;
    int getDestination() const;
    int getHI() const;
    int getHF() const;

};


#endif //PRACTICA_TRANSITION_H

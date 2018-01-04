//
// Created by elenaruiz on 3/01/18.
//

#include "Flight.h"

Flight::Flight(int origin, int destination, int hI, int hF) : origin(origin), destination(destination), hI(hI),
                                                                      hF(hF) {}

int Flight::getOrigin() const {
    return this->origin;
}

int Flight::getDestination() const {
    return this->destination;
}

int Flight::getHI() const {
    return this->hI;
}

int Flight::getHF() const {
    return this->hF;
}
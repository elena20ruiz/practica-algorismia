#include "Transition.h"


Transition::Transition(int origin, int destination, int hI, int hF) {
    this->origin = origin;
    this->destination = destination;
    this->hF = hF;
    this->hI = hI;
}

int Transition::getOrigin() const {
    return origin;
}

void Transition::setOrigin(int origin) {
    this->origin = origin;
}

int Transition::getDestination() const {
    return destination;
}

void Transition::setDestination(int destination) {
    this->destination = destination;
}

int Transition::getHI() const {
    return hI;
}

void Transition::setHI(int hI) {
    this->hI = hI;
}

int Transition::getHF() const {
    return hF;
}

void Transition::setHF(int hF) {
    this->hF = hF;
}

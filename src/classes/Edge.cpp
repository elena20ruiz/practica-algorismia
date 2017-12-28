#include "Edge.h"


Edge::Edge(int origin, int destination, int hI, int hF) {
    this->origin = origin;
    this->destination = destination;
    this->hF = hF;
    this->hI = hI;
}

int Edge::getOrigin() const {
    return origin;
}

void Edge::setOrigin(int origin) {
    this->origin = origin;
}

int Edge::getDestination() const {
    return destination;
}

void Edge::setDestination(int destination) {
    this->destination = destination;
}

int Edge::getHI() const {
    return hI;
}

void Edge::setHI(int hI) {
    this->hI = hI;
}

int Edge::getHF() const {
    return hF;
}

void Edge::setHF(int hF) {
    this->hF = hF;
}
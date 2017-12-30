

#ifndef PRACTICA_TRANSITIONS_H
#define PRACTICA_TRANSITIONS_H

class Edge {

private:
    int origin;
    int destination;
    int hI;
    int hF;

public:

    Edge();

    Edge(int origin, int destination, int hI, int hF);

    int getOrigin() const;

    void setOrigin(int origin);

    int getDestination() const;

    void setDestination(int destination);

    int getHI() const;

    void setHI(int hI);

    int getHF() const;

    void setHF(int hF);

};

#endif //PRACTICA_TRANSITIONS_H

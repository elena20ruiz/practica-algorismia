
#include "Network.h"

Network::Network() = default;

Network::Network(const vector<vector<int> >  &flights, const vector<int> &cities) {

    this->indMatrix = vector< map<int,int> >(cities.size()+2);

    //Inicialización de nodos:
    Node source(-1);
    this->nodes.push_back(source);
    this->idNodes[-1] = 0;

    for(int i = 1; i <= cities.size(); ++i) {

        this->nodes.emplace_back(Node(cities[i]));
        this->idNodes[cities[i]] = i;

    }
    Node sink(-2);
    int posSink = cities.size()+1;
    this->nodes.push_back(sink);
    this->idNodes[-2] = posSink;

    int aux_origen, aux_destino;
    int num = flights.size();
    for(int i = 0; i < num; ++i) {

        //Posicion de nuestro vector de las ciudades
        aux_origen = this->idNodes[flights[i][0]];
        aux_destino = this->idNodes[flights[i][1]];

        // 1. Añadimos conexion source (pos 0)
        this->adjMatrix[0][aux_origen] = true;
        this->capMatrix[0][aux_origen] = 1;

        // 2. Añadimos conexion entre las dos ciudades
        this->adjMatrix[aux_origen][aux_destino] = true;
        this->capMatrix[aux_origen][aux_destino] = 1;

        // 3. Añadimos conexion con sink (pos size + 1)
        this->adjMatrix[aux_destino][posSink] = true;
        this->capMatrix[aux_destino][posSink] = 1;

        Edge edge(flights[i][0], flights[i][1],flights[i][2], flights[i][3]);
        int idEdge = this->edges.size();
        this->edges.push_back(edge);
        this->idEdges[idEdge] = edge;

        //Añadimos relacion entre objetos
        this->nodes[aux_origen].addFligth(idEdge);
    }


}

int Network::existAdjacency(int i, int j) {
    return this->adjMatrix[i][j];
}

int Network::getCapacity(int i, int j) {
    return this->capMatrix[i][j];
}

int Network::getFlow(int i, int j) {
    return this->flowMatrix[i][j];
}

void Network::setFlow(int i, int j, int f) {
    this->flowMatrix[i][j] = f;
}

void Network::setCapacity(int i, int j, int f) {
    this->capMatrix[i][j] = f;

}





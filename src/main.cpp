#include <iostream>
#include <fstream>
#include <vector>
#include "problem/SolverBi.h"
#include "problem/SolverCir.h"
#include <ctime>

void iniFiles();
void readFlights(vector<Flight> &flights, string f);
void ejecutar_tests(int version);
void runTest(vector<Flight> &flights, int version, string f);
void ejecutar_facil(int x);

using namespace std;


int main() {


    iniFiles();

    cout << "Escoge opción:" << endl;

    cout << "1. Ejecutar test grafo circulacion version 1" << endl;
    cout << "2. Ejecutar test grafo bipartido version 1" << endl;
    cout << "3. Ejecutar test grafo bipartido version 2" << endl;


    int x;
    //cin >> x;
    x = 2;
    ejecutar_tests(x);
    ejecutar_facil(x);
}

void ejecutar_facil(int x) {
    string root = "../input2.txt";
    vector<Flight> flights;
    readFlights(flights, root);
    runTest(flights,x,root);
}

void ejecutar_tests(int version) {
    int n;
    int instance = 10;
    string root = "instance_100_";
    while(instance <= 10) {
        n = 1;
        while (n <= 10) {

            string ins = to_string(instance);
            string strn = to_string(n);

            string root = "../Benchmark/" + root + ins + string("_") + strn + string(".air");
            string file = ins + "_" + strn;


            // LLAMADA ALGORISMO----------------------------------
            vector<Flight> flights;
            readFlights(flights,root);
            runTest(flights,version,file);


            //----------------------------------------------------
            ++n;
        }
        ++instance;
    }
}

void iniFiles() {

    // INI CSV--------------------------------------------------------
    ofstream csv;
    csv.open ("time.csv", fstream::in | fstream::out | fstream::app);
    csv << "id_exp;" <<  "n_flights;" << "pilots;" << "time;" << endl;
    csv.close();

    // INI CSV-V2 ----------------------------------------------------
    ofstream csv2;
    csv2.open ("time2.csv", fstream::in | fstream::out | fstream::app);
    csv2 << "id_exp;" <<  "n_flights;" << "pilots;" << "time;" << endl;
    csv2.close();

}

void runTest(vector<Flight> &flights, int version, string f) {

    clock_t begin_time = clock();

    int pilots;

    if(version == 1) {
        SolverCir S(flights);
        //S.runAlgorithm(root);
        pilots = S.getNPilots();
    }
    else if(version == 2) {
        SolverBi S(flights,version);
        S.runAlgorithm(f,version);
        pilots = S.getNPilots();

    }
    else if(version == 3) {
        SolverBi S(flights,version);
        S.runAlgorithm(f,version);
        pilots = S.getNPilots();
    }

    ofstream csv;
    csv.open ("time.csv", fstream::in | fstream::out | fstream::app);
    csv << f << ";" <<  flights.size() << ";"
        << pilots << ";" << time << ";" << endl;
    csv.close();

}

void readFlights(vector<Flight> &flights, string f) {

    ifstream file(f);
    if(file.good()) {
        string o;
        int origen, destination, hI, hF;

        while (file >> o >> destination >> hI >> hF) {

            origen = std::stoi(o);
            Flight transition(origen, destination, hI, hF);
            flights.push_back(transition);

        }
    }
    else "BAD";

}


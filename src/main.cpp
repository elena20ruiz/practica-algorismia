#include <iostream>
#include <fstream>
#include <vector>
#include "problem/Solver.h"
#include <string.h>

void readFile(string root, int version, string id);

using namespace std;


int main() {

    vector<Flight> flights;

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


    int n;
    int instance = 2;
    string root = "instance_100_";
    while(instance <= 30) {
        n = 1;
        while (n <= 10) {

            string ins = to_string(instance);
            string strn = to_string(n);
            string file = "Benchmark/" + root + ins + string("_") + strn + string(".air");

            file = "input.txt";
            readFile(file,0,ins + "_" + strn);
            ++n;
        }
        ++instance;
    }

/*

    Flight transition(0,1,0,300);
    flights.push_back(transition);
    Flight transition2(1,2,400,500);
    flights.push_back(transition2);
    Flight transition3(1,2,500,600);
    flights.push_back(transition3);

    Solver solver(flights,0);
    solver.runAlgorithm("la");
*/

}


void readFile(string root, int version, string id_exp) {

    ifstream file(root);
    if(file.good()) {
        vector<Flight> flights;
        string o;
        int origen, destination, hI, hF;

        while (file >> o >> destination >> hI >> hF) {

            origen = std::stoi(o);

            Flight transition(origen, destination, hI, hF);
            flights.push_back(transition);

        }



        // VERSION 1------------------------------------------------------
       clock_t begin_time = clock();

        Solver solver(flights,0);
        solver.runAlgorithm(root,0);

        float time = float( clock () - begin_time ) /  CLOCKS_PER_SEC ;

        ofstream csv;
        csv.open ("time.csv", fstream::in | fstream::out | fstream::app);
        csv << id_exp << ";" <<  flights.size() << ";"
                    << solver.getNPilots() << ";" << time << ";" << endl;
        csv.close();
        // ----------------------------------------------------------------


        // VERSION 2 ------------------------------------------------------
        begin_time = clock();

        solver = Solver(flights,1);
        solver.runAlgorithm(root,1);

        time = float( clock () - begin_time ) /  CLOCKS_PER_SEC ;


        ofstream csv2;
        csv2.open ("time2.csv", fstream::in | fstream::out | fstream::app);
        csv2 << id_exp << ";" <<  flights.size() << ";"
            << solver.getNPilots() << ";" << time << ";" << endl;
        csv2.close();
        //------------------------------------------------------------------




    }
    else cout << "BAD" << endl;

}


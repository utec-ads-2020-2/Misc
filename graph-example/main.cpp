#include <iostream>

#include "graph.h"

using namespace std;

struct Airport {
    int id;
    string name;
    string city;

    Airport(int id, string name, string city) {
        this->id = id;
        this-> name = name;
        this->city = city;
    }
};

int main(int argc, char *argv[]) {
    Graph<Airport, double> airports;
    Airport lima(1, "Lima", "Lima");
    Airport aqp(1, "AQP", "AQP");

    airports.insertVertex(lima.id, lima);
    airports(lima, aqp) = 5;

    auto lima1 = airports[lima.id];

    graph test;
    return EXIT_SUCCESS;
}
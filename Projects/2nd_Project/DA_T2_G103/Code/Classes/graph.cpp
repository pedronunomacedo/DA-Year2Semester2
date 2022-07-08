#include "graph.h"
#include <queue>
#include <sstream>

using namespace std;
Graph::Graph() {
    stops.clear();
}

Graph::Graph(int num, bool stops) : nr_stops(num), stops(num + 1) {}


void Graph::addBus(int src, int dest, int capacity, int duration) {
    if (src < 1 || src > nr_stops || dest < 1 || dest > nr_stops || capacity < 1 || capacity > nr_stops || duration < 1 || duration > nr_stops )
        return;
    stops[src-1].adj.push_back({src, dest,capacity,duration});

}


int Graph::getNrStops() const {
    return nr_stops;
}

int Graph::getNrBuses() const {
    return nr_buses;
}

void Graph::setNrStops(int num_stops) {
    nr_stops = num_stops;
}

void Graph::setNrBuses(int num_buses) {
    nr_buses = num_buses;
    stops.resize(nr_stops + 1);
}

const vector<Stop> &Graph::getStops() const {
    return stops;
}

bool Graph::readData(string filename) {
    fstream file(filename);
    string firstline, line;
    int id = 0;

    if (!file.is_open()) {
        cout << "File " << filename << " doesn't exist\n";
        return false;
    }

    getline(file, firstline);
    int nr_stops, nr_buses;
    istringstream iss1(firstline);
    iss1 >> nr_stops >> nr_buses;
    setNrStops(nr_stops);
    setNrBuses(nr_buses);
    while (getline(file, line)) {
        id++;
        int source, target, capacity, duration;
        istringstream iss(line);
        iss >> source >> target >> capacity >> duration;
        Bus p{source, target, capacity, duration};
        buses.push_back(p);
        //g.addBus(source, target, capacity, duration);
        addBus(source, target, capacity, duration);
    }
    file.close();
    return true;
}

vector<Bus>& Graph::getBuses() {
    return buses;
}

//
// Created by Utilizador on 24/05/2022.
//

#ifndef PROJECT2_DA_GRAPH_H
#define PROJECT2_DA_GRAPH_H

#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <fstream>
#include <cfloat>
#include <climits>
#include <queue>
using namespace std;

struct Bus {
    int src;
    int dest;
    int capacity;
    int duration;
};

struct Stop {
    vector<Bus> adj;
    double dist;
    int pred;
    bool visited;
    double ES;
    int GrauE;
};


class Graph {
private:

    int nr_stops;
    vector<Stop> stops;
    int nr_buses;
    vector<Bus> buses;

public:
    Graph();
    bool readData(string filename);
    void setNrStops(int num_stops);
    void setNrBuses(int num_buses);
    int getNrStops() const;
    int getNrBuses() const;
    explicit Graph(int stops, bool dir = false);
    void addBus(int src, int dest, int capacity, int duration);
    vector<Stop> getStops() { return stops; };
    const vector<Stop> &getStops() const;
    vector<Bus>& getBuses();
};

#endif //PROJECT2_DA_GRAPH_H

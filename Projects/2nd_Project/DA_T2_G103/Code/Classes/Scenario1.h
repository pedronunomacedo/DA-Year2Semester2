//
// Created by gonzallito on 30-05-2022.
//

#ifndef PROJECT2_DA_SCENARIO1_H
#define PROJECT2_DA_SCENARIO1_H

#include <stdlib.h>
#include <iostream>
#include "graph.h"
using namespace std;

class Scenario1 {
private:
    int V;
public:
    Scenario1();
    void setNrVertices(int v);
    void printpath(vector<int>& parent, int vertex, int target);
    bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[]);
    int scenario1_1(vector<vector<tuple<int, int, int> > >& Graph, int src, int target);
    void scenario1_2(vector<int> adj[], int s, int dest, int v);
    //vector<list<int>> getAdj() {return adj;}
};


#endif //PROJECT2_DA_SCENARIO1_H

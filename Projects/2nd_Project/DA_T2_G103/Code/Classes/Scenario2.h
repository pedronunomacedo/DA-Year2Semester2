//
// Created by gonzallito on 31-05-2022.
//

#ifndef PROJECT2_DA_SCENARIO2_H
#define PROJECT2_DA_SCENARIO2_H

#include <stdlib.h>
#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include "graph.h"

using namespace std;


class Scenario2 {
private:
    Graph g;
    vector<Stop> stops;
    vector<int> path;
    int no_vertices;
public:
    Scenario2();
    void setNrVertices(int v);
    bool bfs(vector<vector<int> > &rGraph, int s, int t, vector<int> &parent);
    void scenario2_1(vector<vector<int> > graph, int s, int t, int size);
    void scenario2_2(vector<vector<int> > graph, int s, int t, int size);
    void scenario2_3(vector<vector<int> > graph, int s, int t);
    void scenario2_4(vector<vector<int>> graph);
};


#endif //PROJECT2_DA_SCENARIO2_H

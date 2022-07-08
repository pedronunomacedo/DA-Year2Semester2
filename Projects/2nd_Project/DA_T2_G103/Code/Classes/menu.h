//
// Created by Utilizador on 24/05/2022.
//

#ifndef PROJECT2_DA_MENU_H
#define PROJECT2_DA_MENU_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <climits>
#include "Scenario1.h"
#include "Scenario2.h"

using namespace std;

class Menu {
private:
    vector<Bus> buses;
    vector<Stop> stops;
    Graph g;
    vector<vector<tuple<int, int, int> > > graph;
    int no_vertices;
    Scenario1 scenario1;
    Scenario2 scenario2;
public:
    Menu();
    bool pass();
    void mainMenu() const;
    void add_edge(vector<int> adj[], int src, int dest);
    void showMenuScenario1();
    tuple<int,int> showMenuScenario1_1();
    tuple<int,int> showMenuScenario1_2();
    void showMenuScenario2();
    tuple<int,int,int> showMenuScenario2_1();
    tuple<int,int,int> showMenuScenario2_2(int opt);
    tuple<int,int> showMenuScenario2_3();
    tuple<int,int,int> showMenuScenario2_4();
    void run();
};
#endif //PROJECT2_DA_MENU_H

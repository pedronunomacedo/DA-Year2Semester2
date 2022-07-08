#include "menu.h"

Menu::Menu() {
    cout << "Enter the file: ";
    string fileName;
    cin >> fileName;
    g.readData("../files/Tests_B/" + fileName);
    buses = g.getBuses();
    no_vertices = g.getNrStops();
    stops = g.getStops();

    graph.assign(no_vertices + 1, vector<tuple<int, int, int> >());
    for (auto & bus : buses) {
        graph[bus.src].push_back(make_tuple(bus.capacity, bus.dest, bus.duration));
    }

    scenario1.setNrVertices(no_vertices);
    scenario2.setNrVertices(no_vertices + 1);
}

bool Menu::pass() {
    if (cin.good())
        return true;
    else {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\n Invalid input!\n";
        return false;
    }
}

void Menu::mainMenu() const {
    cout << endl;
    cout << " ========================================" << endl;
    cout << " ||      Management of applications    ||" << endl;
    cout << " ||          for the transport of      ||" << endl;
    cout << " ||            groups of people        ||" << endl;
    cout << " ========================================" << endl;
    cout << endl;

    cout << " Choose an option:" << endl;
    cout << " [1] 1- Referral from a group that does not part" << endl;
    cout << " [2] 2- Referral from a group that is going to part" << endl;
    cout << " [0] Exit" << endl;
    cout << endl;
}

void Menu::add_edge(vector<int> adj[], int src, int dest) {
    adj[src].push_back(dest);
}

void Menu::showMenuScenario1() {
    cout << endl;
    cout << " ===========================================" << endl;
    cout << " || Scenario 1 - Group that does not part ||" << endl;
    cout << " ===========================================" << endl;
    cout << endl;

    cout << " Choose an option:" << endl;
    cout << " [1] 1.1 - Maximize the size of the group and indicate any route" << endl;
    cout << " [2] 1.2 - Maximize group size and minimize the number of transshipments" << endl;
    cout << " [0] Go back" << endl;
    cout << endl;
}

tuple<int,int> Menu::showMenuScenario1_1() {
    int source;
    int target;

    cout << endl;
    cout << " ==========================================================================" << endl;
    cout << " || Scenario 1.1 - Maximize the size of the group and indicate any route ||" << endl;
    cout << " ==========================================================================" << endl;
    cout << endl;

    cout << " > Source: "; cin >> source;
    cout << " > Target: "; cin >> target;
    cout << endl;

    return {source,target};
}

tuple<int,int> Menu::showMenuScenario1_2() {
    int source;
    int target;

    cout << endl;
    cout << " ==================================================================================" << endl;
    cout << " || Scenario 1.2 - Maximize group size and minimize the number of transshipments ||" << endl;
    cout << " ==================================================================================" << endl;
    cout << endl;

    cout << " > Source: "; cin >> source;
    cout << " > Target: "; cin >> target;
    cout << " \n Choose an option: " << endl;
    cout << " [1] 1.2.1 - Maximize group size" << endl;
    cout << " [2] 1.2.2 - Minimize the number of transshipments" << endl;
    cout << " >";

    return {source,target};
}

void Menu::showMenuScenario2() {
    cout << endl;
    cout << " ==============================================" << endl;
    cout << " || Scenario 2 - Group that is going to part ||" << endl;
    cout << " ==============================================" << endl;
    cout << endl;

    cout << " Choose an option:" << endl;
    cout << " [1] 2.1 - Determine the path for a group, given its size" << endl;
    cout << " [2] 2.2 - Fix a path, if necessary, so that the group size can increase by a given number of units" << endl;
    cout << " [3] 2.3 - Determine the maximum group size and a routing" << endl;
    cout << " [4] 2.4 - Starting from a route that constitutes an acyclic graph, determine when the group would meet again at the destination, at least" << endl;
    cout << " [5] 2.5 - Assuming that the elements that leave the same place leave that place at the same time (and as early as possible), \n     indicate the maximum waiting time and the places where there would be elements that wait that time" << endl;
    cout << " [0] Exit" << endl;
    cout << endl;
}

tuple<int,int,int> Menu::showMenuScenario2_1() {
    int source;
    int target;
    int size;

    cout << endl;
    cout << " ==========================================================================" << endl;
    cout << " ||    Scenario 2.1 - Determine the path for a group, given its size      ||" << endl;
    cout << " ==========================================================================" << endl;
    cout << endl;

    cout << " > Source: "; cin >> source;
    cout << " > Target: "; cin >> target;
    cout << " > Size: "; cin >> size;
    cout << endl;

    return {source,target,size};
}

tuple<int,int,int> Menu::showMenuScenario2_2(int opt) {

    if (opt == 1) {
        int numPeople = 0;
        cout << " How many people do you want to add? ";
        cin >> numPeople;
        cout << endl;
        if (pass()) {
            return {numPeople, -1, -1};
        }
    }
    else if (opt == 2) {cout << endl;
        cout << " ====================================================================================================================" << endl;
        cout << " ||    Scenario 2.2 - Fix a path, if necessary, so that the group size can increase by a given number of units     ||" << endl;
        cout << " ====================================================================================================================" << endl;
        cout << endl;

        int source, target, size;
        cout << " > Source: "; cin >> source;
        cout << " > Target: "; cin >> target;
        cout << " > Size: "; cin >> size;
        cout << endl;

        return {source, target, size};
    }
}

tuple<int,int> Menu::showMenuScenario2_3() {
    int source;
    int target;

    cout << endl;
    cout << " ==========================================================================" << endl;
    cout << " ||    Scenario 2.3 - Determine the maximum group size and a routing      ||" << endl;
    cout << " ==========================================================================" << endl;
    cout << endl;

    cout << " > Source: "; cin >> source;
    cout << " > Target: "; cin >> target;
    cout << endl;

    return {source,target};
}

tuple<int,int,int> Menu::showMenuScenario2_4() {

    cout << endl;
    cout << " ======================================================================================" << endl;
    cout << " ||    Scenario 2.4 - Starting from a route that constitutes an acyclic graph,        ||" << endl;
    cout << " ||                   determine when the group would meet again at the destination,   ||" << endl;
    cout << " ||                   at least                                                        ||" << endl;
    cout << " =======================================================================================" << endl;
    cout << endl;

}

void Menu::run() {
    while (true) {
        mainMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            if (option == 1){ // Scenario 1 - Group that does not part
                showMenuScenario1();
                cout << " >";

                int option1;
                cin >> option1;

                if (pass()){
                    if (option1 == 1) { // 1.1 - Maximize the size of the group and indicate any route
                        tuple<int,int> result = showMenuScenario1_1();
                        int source = get<0>(result);
                        int target = get<1>(result);
                        cout << scenario1.scenario1_1(graph, source, target) << endl;
                    }
                    else if (option1 == 2) { // 1.2 - Maximize group size and minimize the number of transshipments.
                        int option2;
                        tuple<int,int> result = showMenuScenario1_2();
                        int source = get<0>(result);
                        int target = get<1>(result);
                        cin >> option2;
                        vector<int> adj[no_vertices+1];
                        for (auto bus : buses) {
                            add_edge(adj, bus.src, bus.dest);
                        }
                        if (option2 == 1) cout << scenario1.scenario1_1(graph, source, target) << endl; // Maximize group size
                        else if (option2 == 2) {
                            scenario1.scenario1_2(adj, source, target, no_vertices+1); // Minimize number of transhipments
                            cout << endl;
                        }
                    }
                }
            }
            else if (option == 2){ // Scenario 2 - Group that is going to part
                showMenuScenario2();
                cout << " >";

                int option1;
                cin >> option1;

                if (pass()){
                    vector<vector<int> > mygraph(graph.size() , vector<int> (graph.size()));

                    for (int i = 0; i <= g.getNrStops(); i++) {
                        for (int j = 0; j <= g.getNrStops(); j++) {
                            mygraph[i][j] = 0;
                        }
                    }

                    for (int s = 0; s < g.getNrStops(); s++) {
                        vector<Bus> adjacent = g.getStops()[s].adj;
                        for (auto & it : adjacent) {
                            mygraph[s][it.dest-1] = it.capacity;
                        }

                    }
                    if (option1 == 1) { // 2.1 - Determine the path for a group, given its size
                        tuple<int,int,int> result = showMenuScenario2_1();
                        int source = get<0>(result);
                        int target = get<1>(result);
                        int size = get<2>(result);
                        scenario2.scenario2_1(mygraph, source, target, size);
                        string option3;
                        cout << "\n Do you want to add more people (yes/no)? ";
                        cin >> option3;
                        if (pass() && (option3 == "yes" || option3 == "y")) {
                            tuple<int,int,int> res = showMenuScenario2_2(option1);
                            size += get<0>(res);
                            scenario2.scenario2_2(mygraph, source, target, size);
                        }
                        else if (pass() && (option3 == "no" || option3 == "n")) continue;
                    }
                    else if (option1 == 2) { // 2.2 - Fix a path, if necessary, so that the group size can increase by a given number of units
                        tuple<int,int,int> result = showMenuScenario2_2(option1);
                        int source = get<0>(result);
                        int target = get<1>(result);
                        int size = get<2>(result);
                        scenario2.scenario2_2(mygraph, source, target, size);
                        string option3;
                        cout << "\n Do you want to add more people (yes/no)? ";
                        cin >> option3;
                        if (pass() && (option3 == "yes" || option3 == "y")) {
                            tuple<int,int,int> res = showMenuScenario2_2(1);
                            size += get<0>(res);
                            scenario2.scenario2_2(mygraph, source, target, size);
                        }
                        else if (pass() && (option3 == "no" || option3 == "n")) continue;
                    }
                    else if (option1 == 3) { // 2.3 - Determine the maximum group size and a routing
                        tuple<int,int> result = showMenuScenario2_3();
                        int source = get<0>(result);
                        int target = get<1>(result);
                        scenario2.scenario2_3(mygraph, source, target);
                    }
                    else if (option1 == 4) { // 2.4 - Starting from a route that constitutes an acyclic graph, determine when the group would meet again at the destination, at least
                        tuple<int,int,int> result = showMenuScenario2_4();
                        scenario2.scenario2_4(mygraph);
                    }
                    else if (option == 5) { // 2.5 - Assuming that the elements that leave the same place leave that place at the same time (and as early as possible), indicate the maximum waiting time and the places where there would be elements that wait that time

                    }
                }
            }
            else if (option == 0) {
                exit(1);
            }
            else {
                cout << "\n Invalid input!\n";
            }
        }
    }
}


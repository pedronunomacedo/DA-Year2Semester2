//
// Created by gonzallito on 30-05-2022.
//

#include "Scenario1.h"

Scenario1::Scenario1() {

}

void Scenario1::setNrVertices(int v) {
    this->V = V;
}

void Scenario1::printpath(vector<int> &parent, int vertex, int target) {
    if (vertex == 0) {
        return;
    }

    printpath(parent, parent[vertex], target);

    cout << vertex << (vertex == target ? "\n" : "--");
}

bool Scenario1::BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[]) {
    list<int> queue;

    bool visited[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visited[adj[u][i]]) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}


int Scenario1::scenario1_1(vector<vector<tuple<int,int,int>>> &Graph, int src, int target) {
    vector<int> widest(Graph.size(), INT_MIN);

    vector<int> parent(Graph.size(), 0);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater< > > container;

    container.push(make_pair(0, src));

    widest[src] = INT_MAX;

    while (!container.empty()) {
        pair<int, int> temp = container.top();

        int current_src = temp.second;

        container.pop();

        for (auto vertex : Graph[current_src]) {

            int distance = max(widest[get<1>(vertex)],
                               min(widest[current_src], get<0>(vertex)));

            if (distance > widest[get<1>(vertex)]) {

                widest[get<1>(vertex)] = distance;

                parent[get<1>(vertex)] = current_src;

                container.push(make_pair(distance, get<1>(vertex)));
            }
        }
    }

    cout << endl << " The path is: "; printpath(parent, target, target);
    cout << " The maximum capacity is: ";
    return widest[target];
}

void Scenario1::scenario1_2(vector<int> adj[], int s, int dest, int v) {
    int pred[v+1], dist[v+1];
    if (!BFS(adj, s, dest, v+1, pred, dist)) {
        cout << "Given source and destination are not connected";
        return;
    }
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    cout << endl << " The path is : ";
    for (int i = path.size() - 1; i >= 0; i--) {
        if (i != 0) cout << path[i] << "--";
        else cout << path[i];
    }
}
#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int size = G.size();
    if (size == 0 || source >= size) return {}; // empty or out of bounds
    
    vector<int> distances(size, INF);
    distances[source] = 0; // source has no weight
    previous[source] = -1; // there is no previous node to weigh
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source}); // source node

    while (!pq.empty()) {
        auto [dist, eu] = pq.top(); // 
        pq.pop();

        if (dist > distances[eu]) continue; // ignores outdated entries
        for (const Edge& edge : G[eu]) { // ADJ LIST
            int ev = edge.dst; // destination vector
            int weight = edge.weight; // the weight
            if (distances[eu] + weight < distances[ev]) { // is there a shorter path?
                distances[ev] = distances[eu] + weight; // update distance
                previous[ev] = eu;
                pq.push({distances[ev], ev}); // update queue
            }
        }
    }
    return distances;
} // DONE?

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> path;
    if (previous[destination] == INF || previous[destination] == -1) return path; // unreachables
    for (int i = destination; i != -1; i = previous[i]) path.push_back(i); // add it backwards
    reverse(path.begin(), path.end()); // fix it
    return path;
} // DONE?

void print_path(const vector<int>& v, int total)
{
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "\nTotal cost is " << total << "\n";
} // DONE

// g++ -o dj_main src/dijkstras.cpp src/dijkstras_main.cpp
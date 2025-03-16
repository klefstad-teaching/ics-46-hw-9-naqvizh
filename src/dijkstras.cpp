#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int size = G.size();
    if (num == 0 || source < 0 || source >= size) return vector<int>(); // initial checks
    
    vector<int> distances(size, INF);
    distances[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push((source, 0)); // wait is it source 0 or 0 source

    while (!pq.empty()) {
        auto [dist, i] = pq.top();
        pq.pop();

        if (dist > distances[i]) {
            for (const Edge& edge : G(i)) {
                int ev = edge.dst; // destination vector
                int eweight = edge.weight; // the weight
                if (distances[i] + weight < distances[ev]) {
                    distances[ev] = distances[i] + weight;
                    previous[ev] = i;
                    pq.push({distances[i], ev});
                }
            }
        }
    }
    return distances;
} // DONE?

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> path;
    if (previous[destination] == INF || previous[destination] == -1) return path; // unreachable?
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

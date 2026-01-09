//https://www.hackerrank.com/contests/homework-11/challenges/challenge-2774
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to, weight;  
};

void topoSort(int src, unordered_map<int, vector<Edge>>& graph, vector<bool>& visited, stack<int>& topSortStack) {
    visited[src] = true;
    if (graph.find(src) != graph.end()) {
        for (const auto& edge : graph.at(src)) {
            if (!visited[edge.to]) {
                topoSort(edge.to, graph, visited, topSortStack);
            }
        }
    }
    topSortStack.push(src);
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
    int src, dst;
    cin >> src >> dst;
    vector<bool> visited(n, false);
    vector<int> counts(n, 0);
    vector<int> distances (n, -1);
    distances[src] = 0;
    counts[src] = 1;
    
    stack<int> topSortStack;
    topoSort(src, graph, visited, topSortStack);
    while(!topSortStack.empty()) {
        int u = topSortStack.top();
        topSortStack.pop();
        
        if (distances[u] != -1 && graph.find(u) != graph.end()) {
            for (const auto& edge : graph.at(u)) {
                if (distances[u] + edge.weight > distances[edge.to]) {
                    distances[edge.to] = distances[u] + edge.weight;
                    counts[edge.to] = counts[u];
                } else if (distances[u] + edge.weight == distances[edge.to]) {
                    counts[edge.to] += counts[u];
                }
            }
        }
    }
    
    cout << distances[dst] << " " << counts[dst];
    return 0;
}
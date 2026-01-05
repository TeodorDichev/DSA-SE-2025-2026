#include <bits/stdc++.h>
using namespace std;

// negative weights
// no cycles
// directed graph
// topological sort?

struct Edge {
  int to, weight;  
};

void topologicalSort(int curr, unordered_map<int, vector<Edge>>& graph, vector<bool> visited, stack<int>& topSortStack) {
    visited[curr] = true;
    if (graph.find(curr) != graph.end()) {
        for (const auto& edge : graph.at(curr)) {
            if (!visited[edge.to]) {
                topologicalSort(edge.to, graph, visited, topSortStack);
            }
        }
    }
    
    topSortStack.push(curr);
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    if (s == t) return 0;
    
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from - 1].push_back({to - 1, weight});
    }
    
    // -1 is best when searching for longest
    vector<int> distances(n, -1);
    distances[s] = 0;
    
    vector<bool> visited(n, false);
    stack<int> topSortStack;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSort(i, graph, visited, topSortStack);
        }
    }
    
    while (topSortStack.size()) {
        int u = topSortStack.top();
        topSortStack.pop();
        
        if (distances[u] != INT_MAX && graph.find(u) != graph.end()) {
            for (const auto& edge : graph.at(u)) {
                // changed the operator to find the longest road
                if (distances[u] + edge.weight > distances[edge.to]) {
                    distances[edge.to] = distances[u] + edge.weight;
                }
            }
        }
    }
    
    cout << distances[t];
    return 0;
}

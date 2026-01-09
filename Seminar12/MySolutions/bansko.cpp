// https://www.hackerrank.com/contests/sda-hw-10-2024/challenges/challenge-4505/submissions/code/1402720191
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int index, weight;
    
    bool operator <(const Node& other) const {
        return weight > other.weight;
    }
};

struct Edge {
    int to, weight;
};

int main() {
    int v,e,src,dst;
    cin >> v >> e >> src >> dst;
    unordered_map<int, vector<Edge>> graph;
    unordered_map<int, int> waitMap;
    
    for (int i = 0; i < v; i++) {
        int wait;
        cin >> wait;
        waitMap[i] = wait;
    }
    
    for (int i = 0; i < e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
    
    // vector<bool> visited(n);
    vector<int> distances(v, INT_MAX);
    priority_queue<Node> pq;
    
    pq.push({src, 0});
    distances[src] = 0;
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        if (curr.weight > distances[curr.index]) continue;
         if (curr.index == dst) break;
        
        for (auto edge : graph[curr.index]) {
            int t = distances[curr.index];
            int w = waitMap[curr.index];

            int depart = t + (w - t % w) % w;
            int newWeight = depart + edge.weight;

            if (newWeight < distances[edge.to]) {
                distances[edge.to] = newWeight;
                pq.push({edge.to, newWeight});
            }
        }
    }
    
    cout << (distances[dst] == INT_MAX ? -1 : distances[dst]);
    
    return 0;
}

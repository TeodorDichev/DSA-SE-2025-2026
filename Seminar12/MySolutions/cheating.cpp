//https://www.hackerrank.com/contests/sda-homework-10/challenges/challenge-2748/copy-from/1402725029
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, weight;
};

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    
    // bfs 0-1
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back({to, 0});
        graph[to].push_back({from, 0});
    }
    
    for (int i = 0; i < k; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back({to, 1});
        graph[to].push_back({from, 1});
    }
    
    vector<int> distances(n, INT_MAX);
    deque<int> dq;
    dq.push_front(0);
    distances[0] = 0;
    
    while(dq.size()) {
        int curr = dq.front();
        dq.pop_front();
        
        for (auto edge : graph[curr]) {
            int newWeight = distances[curr] + edge.weight;
            if (newWeight < distances[edge.to]) {
                distances[edge.to] = newWeight;
                if (edge.weight) {
                    dq.push_back(edge.to);
                } else {
                    dq.push_front(edge.to);
                }
            }
        }
    }
 
    cout << (distances[n-1] == INT_MAX ? -1 : distances[n-1]);

    return 0;
}
//https://www.hackerrank.com/contests/sda-hw-11-2021/challenges/shortest-paths-2/submissions/code/1402724610
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;;

struct Edge {
    int to;
    long long weight;
    
    bool operator <(const Edge& other) const {
        return weight > other.weight;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    unordered_map<int, vector<Edge>> graph;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        from--;
        to--;
        graph[from].push_back({to, weight});
    }
    
    vector<long long> distances(n, LLONG_MAX);
    vector<long long> ways(n, 0);
    distances[0] = 0;
    ways[0] = 1;
    
    // reusing edge like node
    priority_queue<Edge> pq;
    pq.push({0,0});
    
    while(pq.size()) {
        auto [index, weight] = pq.top();
        pq.pop();
        
        if (weight > distances[index]) continue;
        
        for (auto edge : graph[index]) {
            long long newWeight = weight + edge.weight;
            if (newWeight < distances[edge.to]) {
                distances[edge.to] = newWeight;
                ways[edge.to] = ways[index];
                pq.push({edge.to, newWeight});
            } else if (newWeight == distances[edge.to]) {
                ways[edge.to] = (ways[index] + ways[edge.to]) % MOD;
            }
        }
    }
    
    if(distances[n-1] == LLONG_MAX) cout << -1 << " " << 0 << "\n";
    else cout << distances[n-1] << " " << ways[n-1] << "\n";
    
    return 0;
}

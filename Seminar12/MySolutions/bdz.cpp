// https://www.hackerrank.com/contests/sda-hw-11/challenges/1-143/copy-from/1402503887

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>

using namespace std;

struct Edge {
    int to;
    int len;
    bool isRail;

    Edge(int t, int l, bool r) : to(t), len(l), isRail(r) {}

    friend bool operator<(const Edge& a, const Edge& b){
        if (a.len == b.len) {
            return a.isRail == true;
        }
        
        return a.len > b.len;
    }

};

const long long INF = LLONG_MAX;

int dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    int usedRails = 0;
    vector<bool> visited(n, false);
    vector<long long> dist(n, INF);

    dist[start] = 0;
    priority_queue<Edge, vector<Edge>> q;

    q.push({start, 0, 0});

    while(!q.empty()){
        int v = q.top().to;
        bool isRail = q.top().isRail;

        q.pop();

        if(!visited[v]){
            visited[v] = true;
            if(isRail) usedRails++;

            for(auto edge : graph[v]){
                int to = edge.to;
                int len = edge.len;
                bool type = edge.isRail;

                if(dist[v] + len <= dist[to]){
                    dist[to] = dist[v] + len;
                    Edge e(to, dist[to], type);
                    q.push(e);
                }
            }
        }
    }
    
    return usedRails;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<Edge>> graph(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v,w,false});
        graph[v].push_back({u,w,false});
    }

    for(int i=0; i<k; i++){
        int u, w;
        cin>>u>>w;
        u--;
        graph[u].push_back({0, w, true});
        graph[0].push_back({u, w, true});
    }

    int usedRails = dijkstra(graph, 0);

    cout << k - usedRails << endl;
}
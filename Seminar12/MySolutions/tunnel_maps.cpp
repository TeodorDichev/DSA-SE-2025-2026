//https://www.hackerrank.com/contests/sda-hw-10-2024/challenges/tunnel-maps/submissions/code/1402722962
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, time, weight;
};

bool canReach(int n, int maxWeight, int batteryTime, const vector<vector<Edge>>& graph) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [currTime, u] = pq.top();
        pq.pop();
        if (currTime > dist[u]) continue;

        for (auto& e : graph[u]) {
            if (e.weight > maxWeight) continue;
            int newTime = currTime + e.time;
            if (newTime < dist[e.to]) {
                dist[e.to] = newTime;
                pq.push({newTime, e.to});
            }
        }
    }
    return dist[n-1] <= batteryTime;
}

int main() {
    int n, m, battery;
    cin >> n >> m >> battery;

    vector<vector<Edge>> graph(n);
    int minW = INT_MAX, maxW = 0;

    for (int i = 0; i < m; i++) {
        int from, to, weight, time;
        cin >> from >> to >> weight >> time;
        from--; to--;
        graph[from].push_back({to, time, weight});
        minW = min(minW, weight);
        maxW = max(maxW, weight);
    }

    int left = minW, right = maxW, ans = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canReach(n, mid, battery, graph)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}

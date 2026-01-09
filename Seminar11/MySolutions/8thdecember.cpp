// https://www.hackerrank.com/contests/sda-hw-9-2024/challenges/1-557/copy-from/1402708558
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> friendGroups(n);
    for (int i = 0; i < n; i++) cin >> friendGroups[i];

    int myGroup;
    cin >> myGroup;

    // Multi-source BFS
    vector<int> dist(n, -1);
    vector<int> source(n, -1);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (friendGroups[i] == myGroup) {
            q.push(i);
            dist[i] = 0;
            source[i] = i;
        }
    }

    int answer = INT_MAX;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int nei : graph[curr]) {
            // Not visited yet
            if (dist[nei] == -1) {
                dist[nei] = dist[curr] + 1;
                source[nei] = source[curr];
                q.push(nei);
            } 
            // Already visited: check if from a different source
            else if (source[nei] != source[curr]) {
                answer = min(answer, dist[curr] + dist[nei] + 1);
            }
        }
    }

    cout << answer << "\n";

    return 0;
}

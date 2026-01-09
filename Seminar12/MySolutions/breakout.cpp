// https://www.hackerrank.com/contests/sda-hw-10-2024/challenges/breakout/submissions/code/1402721776
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mtx(n, vector<int>(m, 0));   // 0 = corridor, 1 = wall
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    deque<pair<int,int>> dq;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            if (row[j] == '#') mtx[i][j] = 1;

            // push all border cells (corridor or wall) as starting points
            if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                dq.push_back({i,j});
                dist[i][j] = mtx[i][j]; // 0 if corridor, 1 if wall
            }
        }
    }

    vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    while (!dq.empty()) {
        auto [i,j] = dq.front();
        dq.pop_front();

        for (auto [di,dj] : dirs) {
            int ni = i + di;
            int nj = j + dj;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

            int cost = mtx[ni][nj]; // 0 for corridor, 1 for wall
            if (dist[i][j] + cost < dist[ni][nj]) {
                dist[ni][nj] = dist[i][j] + cost;
                if (cost == 0) dq.push_front({ni,nj});
                else dq.push_back({ni,nj});
            }
        }
    }

    int maxDist = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mtx[i][j] == 0 && dist[i][j] != INT_MAX) { // only corridors
                if (dist[i][j] > maxDist) {
                    maxDist = dist[i][j];
                    count = 1;
                } else if (dist[i][j] == maxDist) {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";
    return 0;
}

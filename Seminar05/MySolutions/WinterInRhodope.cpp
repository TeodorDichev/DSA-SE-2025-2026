// https://www.hackerrank.com/contests/sda-hw-4-2025/challenges/challenge-3724

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M, T;
    cin >> N >> M >> T;

    vector<pair<int,int>> rotten;
    int r, c;
    while (cin >> r >> c) {
        rotten.push_back({r - 1, c - 1}); 
    }

    // bfs
    vector<vector<bool>> grid(N, vector<bool>(M, false));
    queue<pair<int,int>> q;
    for (auto [x, y] : rotten) {
        grid[x][y] = true;
        q.push({x, y});
    }

    int rottenCount = rotten.size();
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int day = 0; day < T; ++day) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && !grid[nx][ny]) {
                    grid[nx][ny] = true;
                    q.push({nx, ny});
                    rottenCount++;
                }
            }
        }
    }

    cout << N * M - rottenCount << "\n";
    return  0;
}
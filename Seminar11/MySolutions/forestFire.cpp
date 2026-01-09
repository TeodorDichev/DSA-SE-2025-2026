//https://www.hackerrank.com/contests/sda-hw-9-2024/challenges/challenge-2753/submissions/code/1402705588
#include <bits/stdc++.h>
using namespace std;

static vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mtx(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> areas;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mtx[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mtx[i][j] == 0 || visited[i][j]) continue;

            int left = j, right = j, up = i, down = i;

            queue<pair<int,int>> q;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                auto [ci, cj] = q.front();
                q.pop();

                left = min(left, cj);
                right = max(right, cj);
                up = min(up, ci);
                down = max(down, ci);

                for (auto [di, dj] : dirs) {
                    int ni = ci + di;
                    int nj = cj + dj;

                    if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                    if (visited[ni][nj]) continue;
                    if (mtx[ni][nj] == 0) continue;

                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }

            areas.push_back((down - up + 1) * (right - left + 1));
        }
    }

    sort(areas.begin(), areas.end(), greater<int>());

    for (int x : areas) {
        cout << x << " ";
    }

    return 0;
}

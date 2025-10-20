#include <iostream>
#include <vector>

// for gods sake labirynth?? ☠️
// umirai ako ne znaesh backtracking
// fucking slow as fuck

using namespace std;

bool isValid(pair<int, int> pos, int n) {
    return pos.first >= 0 && pos.first < n
            && pos.second >= 0 && pos.second < n;
}

bool existsPath(vector<vector<bool>>& maze, pair<int, int> start, pair<int, int> end) {
    if(!isValid(start, maze.size())) return false;
    if(maze[start.first][start.second]) return false;
    if(start.first == end.first && start.second == end.second) return true;

    maze[start.first][start.second] = true;
    bool result = existsPath(maze, {start.first + 1, start.second}, end) ||
                    existsPath(maze, {start.first - 1, start.second}, end) ||
                    existsPath(maze, {start.first, start.second + 1}, end) ||
                    existsPath(maze, {start.first, start.second - 1}, end);
}

int main() {
    int n = 0;
    cin >> n;
    vector<vector<bool>> maze(n, vector<bool>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool val;
            cin >> val;
            maze[i][j] = val;
        }
    }

    cout << existsPath(maze, {0,0}, {n-1, n-1});
}
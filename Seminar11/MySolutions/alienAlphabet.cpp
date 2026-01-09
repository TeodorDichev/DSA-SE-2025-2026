#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> graph;
unordered_set<char> letters;
vector<int> state(26, 0); // 0=unvisited, 1=visiting, 2=done
vector<char> order;

void dfs(char u) {
    state[u - 'a'] = 1;
    for (char v : graph[u]) {
        if (state[v - 'a'] == 0)
            dfs(v);
    }
    state[u - 'a'] = 2;
    order.push_back(u);
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        for (char c : words[i])
            letters.insert(c);
    }

    for (int i = 0; i < n - 1; i++) {
        string &a = words[i];
        string &b = words[i + 1];
        int len = min(a.size(), b.size());

        for (int j = 0; j < len; j++) {
            if (a[j] != b[j]) {
                graph[a[j]].push_back(b[j]);
                break;
            }
        }
    }

    for (char c : letters) {
        if (state[c - 'a'] == 0)
            dfs(c);
    }

    reverse(order.begin(), order.end());

    for (char c : order)
        cout << c << " ";

    return 0;
}

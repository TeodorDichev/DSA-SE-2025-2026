#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> generateHamming(int n) {
    queue<unsigned long long> q2, q3, q5;
    vector<unsigned long long> res;
    res.reserve(n);

    res.push_back(1);

    q2.push(2);
    q3.push(3);
    q5.push(5);

    while ((int)res.size() < n) {
        unsigned long long m = min({q2.front(), q3.front(), q5.front()});
        res.push_back(m);

        if (m == q2.front()) {
            q2.pop();
            q2.push(m * 2);
            q3.push(m * 3);
            q5.push(m * 5);
        }
        else if (m == q3.front()) {
            q3.pop();
            q3.push(m * 3);
            q5.push(m * 5);
        }
        else {
            q5.pop();
            q5.push(m * 5);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    auto v = generateHamming(n);
    for (auto x : v) cout << x << " ";
}

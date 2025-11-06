//https://www.hackerrank.com/contests/sda-hw-5/challenges/challenge-3105/problem?fbclid=IwY2xjawN5O35leHRuA2FlbQIxMQBzcnRjBmFwcF9pZAEwAAEeKrhS2K0rhE0QiEwxDWE0GcgnzlwJsoNDE8CG_J94yD39ht8H1b2H2YmJZZ8_aem_X_M3u-fSYmDnNcM993s8rw

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> hunger(n);
    for (int i = 0; i < n; i++) cin >> hunger[i];

    stack<pair<int, int>> st;
    int maxDays = 0;

    for (int i = 0; i < n; i++) {
        int days = 0;
        
        while (!st.empty() && hunger[i] <= st.top().first) {
            days = max(days, st.top().second);
            st.pop();
        }

        if (st.empty()) {
            days = 0;
        } else {
            days += 1;
        }

        maxDays = max(maxDays, days);
        st.push({hunger[i], days});
    }

    cout << maxDays << "\n";
    return 0;
}
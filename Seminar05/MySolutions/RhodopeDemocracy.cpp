// https://www.hackerrank.com/contests/sda-hw-4-2025/challenges/challenge-3722

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    stack<int> st;
    for(int i = 0; i < N; i++) {
        int rodopchanin = 0;
        cin >> rodopchanin;
        if(rodopchanin >= 0) {
            st.push(rodopchanin);
        }
        else if(st.empty()) {
            cout << rodopchanin << " ";
        }
        else {
            bool equal = false;
            while(!st.empty() && st.top() <= abs(rodopchanin)) {
                if(st.top() == abs(rodopchanin)) {
                    st.pop();
                    equal = true;
                    break;
                }

                st.pop();
            }

            if(st.empty() && !equal) {
                cout << rodopchanin << " ";
            }
        }
    }

    vector<int> survivors;
    while (!st.empty()) {
        survivors.push_back(st.top());
        st.pop();
    }
    
    reverse(survivors.begin(), survivors.end());
    for (int x : survivors) cout << x << " ";
    cout << "\n";
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int num;
        cin >> num;

        auto low = lower_bound(v.begin(), v.end(), num);
        int start = low - v.begin();

        if(low == v.end() || v[start] != num)
            cout << start << "\n";
        else {
            auto upper = upper_bound(v.begin(), v.end(), num);
            int end = (upper - v.begin() - 1);
            cout << start << " " << end << "\n";
        }
    }
}
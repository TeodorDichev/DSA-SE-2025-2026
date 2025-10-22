#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N = 0, Q = 0;
    cin >> N >> Q;
    
    vector<int> students(N), result(Q);
    vector<pair<int, int>> tournaments(Q);
    
    for(int i = 0; i < N; i++)
        cin >> students[i];
    
    for(int j = 0; j < Q; j++)
        cin >> tournaments[j].first >> tournaments[j].second;
    
    sort(students.begin(), students.end());

    for(int j = 0; j < Q; j++) {
        auto start = lower_bound(students.begin(), students.end(), tournaments[j].first);
        auto end = upper_bound(students.begin(), students.end(), tournaments[j].second);
        cout << ((end - start < 0) ? 0 : end - start) << endl;
    }
}

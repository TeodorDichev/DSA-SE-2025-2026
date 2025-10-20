#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool compByFirst(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first < b.first;
}

bool compBySecond(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    int n = 0;
    cin >> n;
    
    vector<pair<string, int>> students(n);
    
    for(int i = 0; i < n; i++) cin >> students[i].first;
    for(int i = 0; i < n; i++) cin >> students[i].second;

    sort(students.begin(), students.end(), compByFirst);
    stable_sort(students.begin(), students.end(), compBySecond);

    for(int i = 0; i < n; i++) cout << students[i].first << " " << students[i].second << endl;

    return 0;
}
// https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/submissions/code/1399380365

#include <bits/stdc++.h>
using namespace std;

vector<long long> cooks;
long long pancakes;

bool isEnoughTimeToCookAllPancakes(long long time) {
    long long sum = 0;
    for (long long cook : cooks) {
        sum += time / cook;
        if (sum >= pancakes) return true;
    }
    return false;
}

void binarySearch(long long& maxTimeForCookingAllPancakes) {
    long long l = 0, r = maxTimeForCookingAllPancakes;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (isEnoughTimeToCookAllPancakes(m)) {
            maxTimeForCookingAllPancakes = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long cooksCnt;
    cin >> pancakes >> cooksCnt;
    cooks.resize(cooksCnt);
    for (long long i = 0; i < cooksCnt; i++) cin >> cooks[i];
    sort(cooks.begin(), cooks.end());

    long long maxTime = pancakes * cooks[cooksCnt - 1];
    binarySearch(maxTime);

    cout << maxTime;
    return 0;
}

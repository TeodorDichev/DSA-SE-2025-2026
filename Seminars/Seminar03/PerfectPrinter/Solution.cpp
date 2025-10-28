// https://www.hackerrank.com/contests/sda-homework-3/challenges/challenge-2674/problem

#include <bits/stdc++.h>
using namespace std;

vector<long long> printers;
long long pages;

bool isEnoughTimeToPrintAllPages(long long time) {
    long long sum = 0;
    for (long long printer : printers) {
        sum += time / printer;
        if (sum >= pages) return true;
    }
    return false;
}

void binarySearch(long long& maxTimeForPrintingAllPages) {
    long long l = 0, r = maxTimeForPrintingAllPages;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (isEnoughTimeToPrintAllPages(m)) {
            maxTimeForPrintingAllPages = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long printersCnt;
    cin >> pages >> printersCnt;
    printers.resize(printersCnt);
    for (long long i = 0; i < printersCnt; i++) cin >> printers[i];
    sort(printers.begin(), printers.end());

    long long maxTime = pages * printers[printersCnt - 1];
    binarySearch(maxTime);

    cout << maxTime;
    return 0;
}

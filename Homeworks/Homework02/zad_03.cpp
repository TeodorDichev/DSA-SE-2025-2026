#include <bits/stdc++.h>
using namespace std;

bool canSplit(const vector<long long>& skills, int teams, long long maxSum) {
    int used = 1;
    long long cur = 0;
    for (long long s : skills) {
        if (cur + s <= maxSum)
            cur += s;
        else {
            ++used;
            cur = s;
            if (used > teams) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<long long> skills(N);
    long long sum = 0, low = 0;

    for (int i = 0; i < N; i++) {
        cin >> skills[i];
        sum += skills[i];
        low = max(low, skills[i]);
    }

    long long high = sum;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canSplit(skills, T, mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
}

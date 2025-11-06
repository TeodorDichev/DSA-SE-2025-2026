// https://www.hackerrank.com/contests/sda-hw-4-2025/challenges/challenge-3723

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    cin >> N >> k;
    if (N == 0 || k == 0 || k > N) return cout << 0, 0;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    long long sum = 0;
    deque<int> dq; // must be empty

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] <= arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }

    for (int i = k; i < N; i++) {
        sum += arr[dq.front()];

        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[i] <= arr[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }

    sum += arr[dq.front()];
    cout << sum;
}

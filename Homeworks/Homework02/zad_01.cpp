#include <iostream>
using namespace std;

int candiesForFriend(long long idx, long long start, long long end, int depth) {
    if(start == end) return depth;

    long long len = end - start + 1;
    long long one_third = len / 3;

    long long mid_start = start + one_third;
    long long mid_end = start + 2 * one_third - 1;

    if(idx >= mid_start && idx <= mid_end) return depth;

    if(idx < mid_start) {
        return candiesForFriend(idx, start, mid_start - 1, depth + 1);
    } else {
        return candiesForFriend(idx, mid_end + 1, end, depth + 1);
    }
}

int main() {
    int P, N;
    cin >> P >> N;

    long long total_friends = 1;
    for(int i = 0; i < P; i++) total_friends *= 3;

    for(int i = 0; i < N; i++) {
        long long f;
        cin >> f;
        cout << candiesForFriend(f - 1, 0, total_friends - 1, 1) << endl;
    }

    return 0;
}

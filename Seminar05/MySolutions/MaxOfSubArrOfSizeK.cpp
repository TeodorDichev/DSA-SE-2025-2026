// https://www.geeksforgeeks.org/dsa/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    vector<int> res;
    deque<int> dq(k);

    for(int i = 0; i < k; i++) {
        while(!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    for (int i = k; i < arr.size(); ++i) {
        res.push_back(arr[dq.front()]);

        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while(!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    res.push_back(arr[dq.front()]);

    return res;
}

int main() {
    vector<int> arr = {1, 3, 2, 1, 7, 3};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}
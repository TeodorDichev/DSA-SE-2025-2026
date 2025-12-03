#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve(const vector<int>& nums, int k) {
    unordered_map<int,int> countMap;
    unordered_map<int,int> firstIndexMap;

    countMap[0] = 1;
    firstIndexMap[0] = -1;

    int sum = 0;
    int resCount = 0;
    int resMaxLength = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int target = sum - k;

        if (countMap.count(target))
            resCount += countMap[target];

        countMap[sum]++;

        if (firstIndexMap.count(target))
            resMaxLength = max(resMaxLength, i - firstIndexMap[target]);

        if (!firstIndexMap.count(sum))
            firstIndexMap[sum] = i;
    }
    
    if (resMaxLength == 0 && resCount == 0) {
        cout << -1;
    } else {
        cout << resMaxLength << " " << resCount;
    }
}

int main() {
    int n, k; 
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    solve(nums, k);
    return 0;
}
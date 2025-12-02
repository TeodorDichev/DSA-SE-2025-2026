#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve(const vector<int>& nums, int k) {
        int sum = 0;
        int resCount = 0;
        int resMaxLength = 0;
        unordered_map<int, int> countMap;
        unordered_map<int, int> firstIndexMap;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int targetPrefix = sum - k;

            if(countMap.count(targetPrefix) != 0)
                resCount += countMap[targetPrefix];
            if(sum == k)
                resCount++;

            countMap[sum]++;

            if(firstIndexMap.count(targetPrefix) != 0)
                resMaxLength = max(i - firstIndexMap[targetPrefix], resMaxLength);
            else 
                firstIndexMap[targetPrefix] = i;
            
            if(sum == k)
                resMaxLength = max(resMaxLength, i+1); // Max is not needed here actually

        }
       
        cout << resMaxLength << ' ' << resCount;
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
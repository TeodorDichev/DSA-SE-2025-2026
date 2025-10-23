// https://leetcode.com/problems/search-insert-position/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto pos = lower_bound(nums.begin(), nums.end(), target);
        return pos - nums.begin();
    }
};
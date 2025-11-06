#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getPivotIndex(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;

            if(m + 1 >= nums.size())
                return m;
            else if(nums[m + 1] < nums[m])  
                return m + 1;

            if(m - 1 < 0)
                return m;
            else if(nums[m] < nums[m - 1])
                return m;

            if(nums[r] > nums[m])
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;
    }

    int binarySearch(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int m = l + (r - l) / 2;

            if(nums[m] == target) 
                return m;

            if(nums[m] < target)
                l = m + 1;
            else 
                r = m - 1;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int pivotIndex = getPivotIndex(nums);
        int start = 0, end = pivotIndex, startSec = pivotIndex, endSec = nums.size() - 1;
        int res1 = binarySearch(nums, target, start, end);
        int res2 = binarySearch(nums, target, startSec, endSec);

        if(res1 == -1 && res2 == -1)
            return -1;
        else if(res1 == -1)
            return res2;
        else 
            return res1;
    }
};

int main() {
    Solution s;
    vector<int> niggers = {4,5,6,7,0,1,2};
    s.search(niggers, 0);
}
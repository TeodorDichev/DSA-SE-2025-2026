// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;

            if(m + 1 >= nums.size())
                return nums[m];
            else if(nums[m + 1] < nums[m])  
                return nums[m + 1];

            else if(m - 1 < 0 || nums[m] < nums[m - 1])
                return nums[m];

            if(nums[r] > nums[m])
                r = m;
            else
                l = m + 1;
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> arr = {11,13,15,17};
    s.findMin(arr);
    return 0;
}
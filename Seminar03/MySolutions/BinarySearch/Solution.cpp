//https://leetcode.com/problems/binary-search/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        
        while(l < r) {
            int m = l + (r - l) / 2;

            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m ;
            else  r = m + 1;
        }

        return -1;
    }
};

int main() {
    Solution s;
    vector<int> arr = {5};
    s.search(arr, 5);
    return 0;
}
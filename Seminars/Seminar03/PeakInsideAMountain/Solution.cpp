// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0, n = arr.size();
        int high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
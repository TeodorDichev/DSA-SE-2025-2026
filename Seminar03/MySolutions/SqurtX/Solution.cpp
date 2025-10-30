
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;

        while(low < high) {
            int mid = low + (high - low) / 2;
            int square = mid * mid;
            if(square == x)
                return mid;
            else if(square > high)
                high = mid;
            else
                mid = low + 1;
        }

        return low;
    }
};

int main() {
    int k = 0;
    cin >> k;
    Solution s;
    s.mySqrt(k);

}
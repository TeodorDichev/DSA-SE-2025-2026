#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Top-Down
    int fibHelper(int n, vector<int>& dp) {
        if(n == 1 || n == 0) {
            return n;
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        return dp[n] = fibHelper(n - 1, dp) + fibHelper(n - 2, dp);
    }

    int fib(int n)
    {
        vector<int> dp(n + 1, -1);

        return fibHelper(n, dp);
    }
};

class Solution {
public:
    // Bottom-up (we do not need DP since we use only the previous two)
    int fib(int n) {
	    if (n == 0 || n == 1) {
	    	return n;
	    }
    
	    long long prevPrev = 0, prev = 1, curr;
	    for (size_t i = 2; i <= n; i++) {
	    	curr = prevPrev + prev;
	    	prevPrev = prev;
	    	prev = curr;
	    }
	    return curr;
    }
};
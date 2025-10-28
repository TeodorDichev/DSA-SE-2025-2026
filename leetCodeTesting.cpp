#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        // brute force

        for(int i = n + 1; i < INT_MAX; i++) {
            unordered_map<int, int> map;
            bool mark = false;
            for(int j = i; j > 0; j /= 10) {
                int d = j % 10;

                if(d == 0) {
                    break;
                    mark = true;
                }
                    
                    
                map[d]++;
            }

            if(mark) 
                continue;
                
            bool all = true;
            for(int k = 1; k < 10; k++) {
                if(map[k] != k) {
                    all = false;
                }
            }

            if(all) return i;
        }

        return -1;
    }
};

int main() {
    Solution s;
    s.nextBeautifulNumber(1);
}
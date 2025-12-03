// От стандартен вход се подават едно по едно числа, 
// като от вас се иска винаги като се получите специалното 
// число 0, да принтирате на екрана кое е най-често срещаното 
// число до момента(ако има няколко които се срещат еднакъв брой 
// пъти принтирайте най-малкото от тях), като след това да нулирате брояча за срещанията му.

// Вход: 1 5 1 5 4 1 4 4 0 0 2 2 0

// Изход: 1 4 2

#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
using namespace std;

int getMostCommon(unordered_map<int, int> map) {
    int maxCnt = -1;
    int res = 0;
    for (auto& it : map) {
        if (it.second > maxCnt) {
            maxCnt = it.second;
            res = it.first;
        }
        else if (it.second == maxCnt) {
            maxCnt = it.second;
            res = it.first > res ? res : it.first;
        }
    }

    return res;
}

void solve(const vector<int>& nums) {
    unordered_map<int, int> map;
    for (int n : nums) {
        if (n == 0) {
            int m = getMostCommon(map);
            if (m != 0) {
                cout << m << " ";
            }
            map[m] = 0;
        } else {
            map[n]++;
        }
    }
}

int main() {
    vector<int> nums = {1, 5, 1, 5, 4, 1, 4, 4, 0, 0, 2, 2, 0};
    solve(nums);
}
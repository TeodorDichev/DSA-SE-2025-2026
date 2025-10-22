#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int decode(char c) {
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 36;
    else return 63; // invalid index never appearing in answer
}

char decode(int c) {
    if(c >= 0 && c <= 9)
        return '0' + c;
    else if(c >= 10 && c <= 35)
        return 'a' + c - 10;
    else if(c >= 36 && c <= 62)
        return 'A' + c - 36;
    else return 63; // invalid index never appearing in answer
}

int main() {
    int max = 63;
    vector<int> cnt_arr(max, 0);
    int n = 0;
    cin >> n;
    string str;
    cin >> str;
    
    for(int i = 0; i < n; i++) {
        cnt_arr[decode(str[i])]++;
    }

    for(int i = 0; i < max; i++) {
        for(int j = 0; j < cnt_arr[i]; j++) {
            cout << decode(i);
        }
    }
    
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    cin >> n;

    vector<int> arr(n);
    for(int i = 1; i <= n; i++) {
        int num = 0;
        cin >> num;

        int j = 0;
        while(j < i - 1 && num > arr[j]) j++;
        arr.insert(arr.begin() + j, num);

        if(i % 2) cout << arr[i / 2] << endl;
        else cout << (arr[i / 2 - 1] + arr[i / 2]) / 2.0 << endl;
    }
    return 0;
}

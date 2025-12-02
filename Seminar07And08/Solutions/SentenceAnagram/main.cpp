#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>


using namespace std;


void solve()
{
    int firstLen, secondLen;
    cin >> firstLen >> secondLen;
    
    unordered_map<string, int> map;
    for(int i = 0; i < firstLen; i++)
    {
        string word;
        cin >> word;
        
        map[word]++;
    }
    bool res = true;
    for(int i = 0; i < secondLen; i++)
    {
        string word;
        cin >> word;
        
        if(map[word] == 0)
        {
            res = false;
        }
        else
        {
            map[word]--;
        }
    }
    
    cout << (res ? "Yes" : "No") << endl;
    return;
}

int main() {

    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++)
    {
        solve();
        
    }
}
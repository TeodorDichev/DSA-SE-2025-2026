//https://www.hackerrank.com/contests/2-2023-2024/challenges/kosi/problem

#include <bits/stdc++.h>
using namespace std;

struct Box {
    int weight;
    int index;
    
    Box(): weight(0), index(0)
    { }
    
    Box(int w, int i): weight(w), index(i)
    { }
};

bool comp(const Box& b1, const Box& b2) {
    return b1.weight < b2.weight;
}

pair<int, int> calcBoxes(int target, const vector<Box>& boxes) {
    int low = 0, high = boxes.size() - 1;
    
    while(low <= high) {
        int sum = boxes[low].weight + boxes[high].weight;
        
        if(sum == target)
            return {min(boxes[low].index, boxes[high].index), max(boxes[low].index, boxes[high].index)};
        else if(sum < target)
            low++;
        else 
            high--;
    }
    
    return {min(boxes[low].index, boxes[high].index), max(boxes[low].index, boxes[high].index)};
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    
    for(int j = 0; j < T; j++) {
        int X, N;
        cin >> X >> N;
        vector<Box> W;
    
        for(int i = 1; i <= N; i++){
            int weight;
            cin >> weight;
            
            W.push_back(Box(weight, i));
        }
        
        sort(W.begin(), W.end(), comp);
        pair<int, int> res = calcBoxes(X, W);
        cout << res.first << " " << res.second << "\n";
    }
    
}
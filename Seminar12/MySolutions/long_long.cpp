// https://www.hackerrank.com/contests/sda-hw-11/challenges/long-long/copy-from/1402505665

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int from, to;
    long long weight;
};

int main() {
    int nodesCount, edgesCount, start, end;
    cin >> nodesCount >> edgesCount >> start >> end;
    
    vector<Edge> edgeList;
    for(int i = 0; i < edgesCount; i++) {
        int from, to;
        long long weight;
        cin >> from >> to >> weight;
        edgeList.push_back({ from, to, -weight });
    }
    
    vector<long long> distances(nodesCount + 1, LLONG_MAX);
    distances[start] = 0;
    for(int i = 0; i < nodesCount; i++) {
        for(int i = 0; i < edgesCount; i++) {
            auto& edge = edgeList[i];
            // usually this is in the if statement
            distances[edge.to] = min(distances[edge.to], distances[edge.from] + edge.weight);
        }
    }
    
    if(distances[end] == LLONG_MAX) {
        cout << -1;
    } else {
        cout << -distances[end];
    }
}
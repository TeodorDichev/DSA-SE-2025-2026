#include <vector>
#include <iostream>
using namespace std;

// Table: DP[i][w] = maximum value that we can get from items [0...i] with weight w
// Rec: DP[i][w] = max(pick, notPick)
// pick = value[i] + DP[i-1][w - weight[i]] (ONLY IF W >= WEIGHT[I])
// notPick = DP[i-1][w]

int knapsackRec(int W, const vector<int> &val, const vector<int> &wt, int n, vector<vector<int>> &memo)
{
    if (n == 0 || W == 0)
        return 0;

    if(memo[n][W] != -1)
        return memo[n][W];

    int pick = 0;
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);
    
    int notPick = knapsackRec(W, val, wt, n - 1, memo);
    
    return memo[n][W] = max(pick, notPick);
}

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    
    return knapsackRec(W, val, wt, n, memo);
}

int main()
{
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}
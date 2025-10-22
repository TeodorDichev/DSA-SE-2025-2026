#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long sum = 0, arraySize, queries;
    cin >> arraySize >> queries;

    vector<int> numbers(arraySize);
    for(long long i = 0; i < arraySize; i++)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    vector<long long> prefixSum;
    for(long long i = 0; i < arraySize; i++) {
        sum += numbers[i];
        prefixSum.push_back(sum);
    }

    for(long long i = 0; i < queries; i++) {
        long long greatest, targetSum;
        cin >> targetSum >> greatest;

        if(targetSum < greatest) printf("%i\n", 0);
        else {
            auto greatestStart = upper_bound(numbers.begin(), numbers.end(), greatest);
            long long greatestStartIndex = (greatestStart - numbers.begin() - 1);
            long long maxSum = prefixSum[greatestStartIndex];
            long long restSum = maxSum - targetSum;
            auto lowerBoundOfRestSum = lower_bound(prefixSum.begin(), prefixSum.end(), restSum);
            long long lowerBoundOfRestSumIndex = lowerBoundOfRestSum - prefixSum.begin();
            if(lowerBoundOfRestSumIndex != 0)
                printf("%i\n", greatestStartIndex - lowerBoundOfRestSumIndex);
            else 
                printf("%i\n", greatestStartIndex - lowerBoundOfRestSumIndex + 1);
        }
    }

    return 0;
}
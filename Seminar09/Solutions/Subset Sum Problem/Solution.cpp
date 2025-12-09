// 04 Subset Sum Problem. Code credit: https://github.com/Angeld55
//// Таблица - DP[i][s] = може ли с елементите [0..i] да получим сума s
//// Rec: DP[i][s] = DP[i-1][s-curr] || DP[i-1][s] (Разглеждаме ако вземем или ако не вземем текущия) 
bool subsetSum(const vector<int>& arr, int sum, vector<int>& subset)
{
	int rows = arr.size() + 1;
	int colls = sum + 1;

	vector<vector<bool>> DP;
	DP.resize(rows, vector<bool>(colls));

	for (int j = 1; j <= sum; j++)
		DP[0][j] = false;

	for (int i = 0; i <= arr.size(); i++)
		DP[i][0] = true;

	for (int i = 1; i <= arr.size(); i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (arr[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j] || DP[i - 1][j - arr[i - 1]];
		}
	}

	//recover elements

	if (!DP[arr.size()][sum])
		return false;

	int sumForRecovery = sum;
	for (int i = arr.size()-1; i >= 0 && sum > 0; i--)
	{
		if (sumForRecovery - arr[i] < 0)
			continue;
		if (DP[i][sumForRecovery - arr[i]])
		{
			subset.push_back(arr[i]);
			sumForRecovery -= arr[i];
		}
	}


	return DP[arr.size()][sum];
}
int main()
{
	// Input: set of items and a sum
	vector<int> arr = { 1, 2, 3, 4, 5 };

	vector<int> result; //if exists
	std::cout << subsetSum(arr, 10, result) <<endl;

	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << "  ";

}
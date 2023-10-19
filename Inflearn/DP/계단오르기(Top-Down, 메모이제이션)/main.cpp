#include <iostream>
using namespace std;

int dp[46];

int DFS(int n)
{
	if (dp[n] != 0)
		return dp[n];

	return dp[n] = DFS(n - 1) + DFS(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);

	int N;

	dp[1] = 1;
	dp[2] = 2;

	cin >> N;
	cout << DFS(N);
}
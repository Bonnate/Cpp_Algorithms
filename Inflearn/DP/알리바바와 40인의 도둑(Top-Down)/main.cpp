#include <iostream>
using namespace std;

int dp[21][21];
int arr[21][21];

int DFS(int x, int y)
{
	if (dp[x][y] != 0)
		return dp[x][y];
	else if (x == 1 && y != 1)
		return  dp[x][y] = DFS(x, y - 1) + arr[x][y];
	else if (x != 1 && y == 1)
		return  dp[x][y] = DFS(x - 1, y) + arr[x][y];
	else
		return dp[x][y] = min(DFS(x - 1, y), DFS(x, y - 1)) + arr[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> arr[i][j];

	dp[1][1] = arr[1][1];

	cout << DFS(N, N);
}
#include <iostream>
using namespace std;

int dp[21][21];
int arr[21][21];

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> arr[i][j];

	dp[1][1] = arr[1][1];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == 1 && j != 1)
				dp[i][j] = dp[i][j - 1] + arr[i][j];
			else if (j == 1 && i != 1)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else
			{
				// 위 누적값이 왼쪽 누적값보다 작으면?(최저)
				if (dp[i][j - 1] < dp[i - 1][j])
					dp[i][j] = dp[i][j - 1] + arr[i][j];
				else
					dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
		}
	}

	cout << dp[N][N];
}
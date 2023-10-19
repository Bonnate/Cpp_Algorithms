#include <iostream>
using namespace std;

int dp[46];

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N + 1; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[N + 1];
}
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dp[12];

	dp[1] = 1; // 1
	dp[2] = 2; // 1+1, 2
	dp[3] = 4; // 1+1+1, 1+2, 2+1, 3
	//dp[4] = 7; // 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1

	int T, n;
	cin >> T;

	for (int i = 4; i < 12; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		cout << dp[n] << endl;
	}
}
#include <iostream>
using namespace std;

int dp[1001];
int numbers[1001];

int main()
{
	int N, ans = INT_MIN;;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> numbers[i];

	dp[0] = 1;

	for (int i = 1; i < N; ++i)
	{
		int max = 0;

		for (int j = i - 1; j >= 0; --j)
		{
			// 뒤 숫자가 더 큰경우 갱신
			if (numbers[j] < numbers[i])
			{
				if (max < dp[j])
				{
					max = dp[j];
				}
			}

			dp[i] = max + 1;
		}

		if (ans < dp[i])
			ans = dp[i];
	}

	cout << ans;
}
#include <iostream>
using namespace std;

int dp[101];
int numbers[101];

int main()
{
	int N, res = INT_MIN;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> numbers[i];

	dp[0] = 1;

	for (int i = 1; i < N; ++i)
	{
		int max = 0;

		for (int j = i - 1; j >= 0; --j)
		{
			if (numbers[i] > numbers[j])
			{
				if (max < dp[j])
					max = dp[j];
			}
		}

		dp[i] = max + 1;
		if (res < dp[i])
			res = dp[i];
	}

	cout << res;
}
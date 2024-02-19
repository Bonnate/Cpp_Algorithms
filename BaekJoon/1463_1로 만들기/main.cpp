#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(1000001);

int main()
{
	int N;
	cin >> N;

	dp[1] = 0;

	// bottom-up
	for (int i = 2; i <= N; ++i)
	{
		// 1을 더해보기
		dp[i] = dp[i - 1] + 1;

		// 3으로 나누어 떨어진다면, 현재 값과, 3으로 나누고 + 1한 값 중 낮은 값을 사용
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);

		// 2로 나누어 떨어진다면, 현재 값과, 2로 나누고 + 1한 값 중 낮은 값을 사용
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N];
}
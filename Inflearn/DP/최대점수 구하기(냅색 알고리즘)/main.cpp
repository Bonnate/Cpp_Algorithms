#include <iostream>
using namespace std;

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);

	int N, M, res = INT_MIN;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int t;
		int s;
		cin >> s >> t;

		// 각 문제당 한번씩만 푼다는 조건이 있기때문에
		// for문을 M부터 t까지 역으로 돌아 현재 score에 대한 중복 적용이 없도록 구현
		for (int j = M; j >= t; --j)
		{
			dp[j] = max(dp[j], dp[j - t] + s);
			res = max(res, dp[j]);
		}
	}

	cout << res;
}
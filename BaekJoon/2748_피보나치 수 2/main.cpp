#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(301, -1);
int input[301];

//int func(int n)
//{
//	// 0보다 작다면 0리턴
//	if (n < 0)
//		return 0;
//
//	int& ret = dp[n];
//
//	// 해당 값이 이미 있다면, 즉시 리턴
//	if (ret != -1)
//		return ret;
//
//	ret = max(ret, func(n - 2) + input[n]); // case1: n-2 계단과 n번 계단을 함께 밟는 경우
//	ret = max(ret, func(n - 3) + input[n - 1] + input[n]); // case2: n-3 계단과 n-1, n번 계단을 함께 밟는 경우
//
//	return ret;
//}

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> input[i];

	dp[0] = 0;
	dp[1] = input[1];
	dp[2] = input[1] + input[2];
	for (int i = 3; i <= N; ++i)
		dp[i] = max(dp[i - 3] + input[i - 1] + input[i], dp[i - 2] + input[i]);

	cout << dp[N];
}
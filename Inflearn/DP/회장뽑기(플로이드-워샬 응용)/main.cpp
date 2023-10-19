#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int N, minScore = INT_MAX, count = 0;
	cin >> N;

	vector<vector<int>> arr(N + 1, vector<int>(N + 1, 1000));
	vector<int> res(N + 1, INT_MIN);

	for (int i = 1; i <= N; ++i)
		arr[i][i] = 0;

	int a, b;
	while (true)
	{
		cin >> a >> b;

		if (a == -1 && b == -1)
			break;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	// 친구 점수를 계산 (플로이드 워샬)
	for (int k = 1; k <= N; ++k)
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	// 점수를 계산하여 결과에 저장
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			res[i] = max(res[i], arr[i][j]);
		}

		// 최저 점수 (회장 후보)
		minScore = min(minScore, res[i]);
	}

	// 회장 후보가 몇명인지 계산
	for (int i = 1; i <= N; ++i)
		if (res[i] == minScore)
			++count;

	cout << minScore << " " << count << endl;
	for (int i = 1; i <= N; ++i)
		if (res[i] == minScore)
			cout << i << " ";
}
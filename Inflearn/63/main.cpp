#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	// 2차원 벡터를 0으로 초기화
	vector<vector<int>> arr(N, vector<int>(N, 0));

	int f, t, w; // from, to, weight
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);

		arr[f - 1][t - 1] = w;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("%d ", arr[i][j]);

		printf("\n");
	}
}
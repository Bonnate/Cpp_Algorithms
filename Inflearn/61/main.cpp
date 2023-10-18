#include <iostream>

int N, M, cnt = 0;
int arr[10];

void recur(int level, int sum)
{
	if (level == N + 1)
	{
		if (sum == M)
			++cnt;
	}
	else
	{
		// 다음 원소는 더하기
		recur(level + 1, sum + arr[level - 1]);

		// 다음 원소는 빼기
		recur(level + 1, sum - arr[level - 1]);

		// 다음 원소는 사용하지 않음
		recur(level + 1, sum);
	}
}

int main()
{
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	recur(1, 0);

	if (cnt == 0)
		printf("-1\n");
	else
		printf("%d\n", cnt);
}
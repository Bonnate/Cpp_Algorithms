#include<stdio.h>

int N, T[16], P[16], res = 0;

void DFS(int L, int sum)
{
	// 모든 선택을 완료하였다면?
	if (L == N + 1)
		if (sum > res)
			res = sum;
		else
		{
			// 현재까지 일정 + 다음 일정이 N + 1보다 작다면, 상담을 시도
			if (L + T[L] <= N + 1)
				DFS(L + T[L], sum + P[L]);

			// 상담을 하지 않는 경우도 재귀로 호출
			DFS(L + 1, sum);
		}
}

int main()
{
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf_s("%d %d", &T[i], &P[i]);

	DFS(1, 0);
	printf("%d\n", res);

	return 0;
}
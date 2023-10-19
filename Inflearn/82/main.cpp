#include <iostream>

int N, R;
int arr[16];
bool ch[16];
int cnt = 0;
int res[16];

void DFS(int level)
{
	// 사용 개수가 R에 도달했다면?
	if (level == R)
	{
		++cnt;

		for (int i = 1; i <= R; ++i)
			printf("%d ", res[i]);

		printf("\n");
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!ch[i])
			{
				// 출력 결과는 res[level + 1]에 담기
				res[level + 1] = arr[i];

				// ch[i]번째의 값을 현재 사용중
				ch[i] = true;

				// 개수는 1씩 증가
				DFS(level + 1);

				// ch[i]번째의 값을 현재 사용 해제
				ch[i] = false;
			}
		}
	}
}

int main()
{
	scanf_s("%d %d", &N, &R);

	for (int i = 1; i <= N; ++i)
	{
		scanf_s("%d", &arr[i]);
	}

	// 0번 인덱스로 시작
	DFS(0);

	printf("%d", cnt);
}
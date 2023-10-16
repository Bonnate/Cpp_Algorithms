#include <iostream>

int main()
{
	int N, cnt = 0;
	scanf_s("%d", &N);

	int** arr = new int* [N];

	for (int i = 0; i < N; ++i)
		arr[i] = new int[N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf_s("%d", &arr[i][j]);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i != 0 && arr[i][j] <= arr[i - 1][j]) // 좌측 검사
				continue;
			else if (i != N - 1 && arr[i][j] <= arr[i + 1][j]) // 우측 검사
				continue;
			else if (j != 0 && arr[i][j] <= arr[i][j - 1]) // 상측 검사
				continue;
			else if (j != N - 1 && arr[i][j] <= arr[i][j + 1]) // 하측 검사
				continue;

			++cnt;
		}
	}

	printf("%d", cnt);
}
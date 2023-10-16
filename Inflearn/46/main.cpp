#include <iostream>

int main()
{
	int N, K;
	scanf_s("%d", &N);

	int* arr = new int[N];
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	scanf_s("%d", &K);

	int idx = 0;
	int emptyCnt = 0;
	while (true)
	{
		if (idx == N)
			idx = 0;

		if (arr[idx] == 0)
		{
			++idx;
			++emptyCnt;

			if (emptyCnt == N)
			{
				printf("-1");
				return 0;
			}

			continue;
		}
		else
		{
			emptyCnt = 0;
			--arr[idx++];
		}

		// 정전이 난 상황
		if (--K == 0)
		{
			if (idx == N)
				idx = 0;

			int currentIdx = idx;

			if (currentIdx == 0)
			{
				for (int i = 0; i < N; ++i)
				{
					if (arr[i] != 0)
					{
						printf("%d", i + 1);
						return 0;
					}
				}
			}
			else
			{
				while (idx != currentIdx - 1)
				{
					if (idx == N)
						idx = 0;

					if (arr[idx] != 0)
					{
						printf("%d", idx + 1);
						return 0;
					}

					++idx;
				}
			}
		}
	}
}
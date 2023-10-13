#include <iostream>
#include <vector>

int main()
{
	int scores[100];
	int rank = 1;

	int resRank[100];

	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &scores[i]);

	for (int i = 100; i >= 0; --i)
	{
		int currentRank = rank;

		for (int j = 0; j < N; ++j)
		{
			if (scores[j] == i)
			{
				resRank[j] = currentRank;
				++rank;
			}
		}
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", resRank[i]);
}
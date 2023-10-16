#include <iostream>

int main()
{
	int** arr = new int* [9];
	int* avg = new int[9];

	for (int i = 0; i < 9; ++i)
	{
		arr[i] = new int[9];
		int sum = 0;

		for (int j = 0; j < 9; ++j)
		{
			scanf_s("%d", &arr[i][j]);
			sum += arr[i][j];
		}

		avg[i] = std::round((float)sum / 9); // ¹İ¿Ã¸²
	}

	for (int i = 0; i < 9; ++i)
	{
		int nearestNum = 0;
		int nearestGap = INT_MAX;

		for (int j = 0; j < 9; ++j)
		{
			int gap = std::abs(avg[i] - arr[i][j]);

			if (gap < nearestGap)
			{
				nearestGap = gap;
				nearestNum = arr[i][j];
			}
		}

		printf("%d %d\n", avg[i], nearestNum);
	}
}
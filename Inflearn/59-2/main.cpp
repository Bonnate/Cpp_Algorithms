#include <iostream>

static int N;

void recur(int arr[], int level, bool isLeft)
{
	arr[level] = isLeft;

	if (level != N - 1)
	{
		recur(arr, level + 1, true);
		recur(arr, level + 1, false);
	}
	else
	{
		for (int i = 0; i < N; ++i)
			if (arr[i])
				printf("%d ", i + 1);

		printf("\n");
	}
}

int main()
{
	scanf_s("%d", &N);

	int* arr = new int[N];

	recur(arr, 0, true);
	recur(arr, 0, false);
}
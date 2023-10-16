#include <iostream>
#include <vector>

int main()
{
	int N;
	scanf_s("%d", &N);

	std::vector<int> arr(N);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	int i, j;

	for (i = 1; i < N; ++i)
	{
		int temp = arr[i];

		for (j = i; j > 0; --j)
			if (arr[j - 1] > temp)
				arr[j] = arr[j - 1];
			else
				break;

		arr[j] = temp;
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
}
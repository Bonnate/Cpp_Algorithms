#include <iostream>

int main()
{
	int arr[100001];

	int N;
	scanf_s("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		scanf_s("%d", &arr[i]);

		int rank = i;
		for (int j = i - 1; j >= 1; --j)
		{
			if (arr[i] > arr[j])
				--rank;
		}

		printf("%d ", rank);
	}
}
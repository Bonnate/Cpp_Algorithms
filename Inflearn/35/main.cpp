#include <iostream>
#include <vector>

void swap(int* a, int* b) noexcept
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int N;
	scanf_s("%d", &N);

	std::vector<int> arr(N);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N - 1 - i; ++j)
			if (arr[j] > arr[j + 1] && arr[j] * arr[j + 1] < 0)
				swap(&arr[j], &arr[j + 1]);

	for (int i = 0; i < N; ++i)
		printf("%d ", arr[i]);
}
#include <iostream>
#include <vector>

void swap(int* a, int* b) noexcept
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

using namespace std;
int main()
{
	int N;
	scanf_s("%d", &N);

	vector<int> numbers(N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &numbers[i]);

	for (int i = 0; i < N - 1; ++i)
	{
		int idx = i;

		for (int j = i + 1; j < N; ++j)
		{
			if (numbers[j] < numbers[idx])
				idx = j;
		}

		swap(numbers[i], numbers[idx]);
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", numbers[i]);
}
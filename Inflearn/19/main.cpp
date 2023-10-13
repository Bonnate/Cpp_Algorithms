#include <iostream>

int main()
{
	int arr[101];
	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	int ans = N - 1;
	for (int i = 0; i < N - 1; ++i)
		for (int j = i + 1; j < N; ++j)
			if (arr[i] <= arr[j])
			{
				--ans;
				break;
			}

	printf("%d", ans);
}
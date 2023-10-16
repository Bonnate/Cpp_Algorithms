#include <iostream>

int getMin(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int N, sum = 0;
	scanf_s("%d", &N);

	int* fView = new int[N];
	int* sView = new int[N];

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &fView[i]);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &sView[i]);

	for (int i = N - 1; i >= 0; --i)
		for (int j = 0; j < N; ++j)
		{
			// 두는 블록은 정면과 측면뷰에서 둘 중 작은 값으로 설정
			int min = getMin(fView[i], sView[j]);
			sum += min;
		}

	printf("%d", sum);
}
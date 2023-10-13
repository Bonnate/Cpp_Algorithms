#include <iostream>

int main()
{
	int temperatures[100001];
	int temperatureSums[100001]{ 0, };
	int maxTempSum = INT_MIN;

	int N, K;
	scanf_s("%d %d", &N, &K);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &temperatures[i]);

	// 첫번째 온도 합 구하기
	for (int i = 0; i < K; ++i)
		temperatureSums[0] += temperatures[i];
	maxTempSum = temperatureSums[0];

	// 나머지 온도 합을 이전 값을 활용하여 구하기
	for (int i = 1; i < N - K + 1; ++i)
	{
		temperatureSums[i] = temperatureSums[i - 1] - temperatures[i - 1] + temperatures[i + K - 1];
		maxTempSum = temperatureSums[i] > maxTempSum ? temperatureSums[i] : maxTempSum;
	}

	printf("%d", maxTempSum);
}
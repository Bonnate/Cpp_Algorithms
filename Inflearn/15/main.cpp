#include <iostream>

static bool isPrime[200001] = { false, };

int main()
{
	for (int i = 2; i < 200001; ++i)
		isPrime[i] = 1;

	for (int i = 2; i <= std::sqrt(200001); ++i)
		for (int j = i * 2; j < 200001; j += i)
			isPrime[j] = false;

	int N;
	scanf_s("%d", &N);

	int answer = 0;
	for (int i = 0; i <= N; ++i)
		if (isPrime[i])
			++answer;

	printf("%d", answer);
}
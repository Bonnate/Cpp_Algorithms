#include <iostream>

int main()
{
	/*
	int N;
	scanf_s("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		int cnt = 0;
		for (int j = 1; j <= i; ++j)
			if (i % j == 0)
				++cnt;

		printf("%d ", cnt);
	}
	*/

	int primes[50001] = { 0, };
	int N;

	scanf_s("%d", &N);

	for (int i = 1; i <= N; ++i)
		for (int j = i; j <= N; j += i)
			++primes[j];

	for (int i = 1; i <= N; ++i)
		printf("%d ", primes[i]);
}
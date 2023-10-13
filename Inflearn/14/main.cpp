#include <iostream>

bool isPrime(int x);
int reverse(int x);

// 에라토스테네스의 체 알고리즘
static bool primes[100001];

int main()
{
	int N, numInput;
	scanf_s("%d", &N);

	// 모두 true로 초기화
	for (int i = 0; i < 100001; ++i)
		primes[i] = 1;

	// 0과 1은 소수가 아님
	primes[0] = primes[1] = false;

	// 에라토스테네스의 체 알고리즘을 통해 모든 소수 판별
	for (int i = 2; i <= std::sqrt(100001); ++i)
	{
		if (!primes[i])
			continue;

		primes[i] = true;
		for (int j = i * 2; j < 100001; j += i)
			primes[j] = false;
	}

	// 나머지 계산
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &numInput);

		int reverseNum = reverse(numInput);
		if (isPrime(reverseNum))
			printf("%d ", reverseNum);
	}
}

bool isPrime(int x)
{
	return primes[x];
}

int reverse(int x)
{
	int num = 0;

	while (x > 0)
	{
		num = num * 10 + x % 10;
		x /= 10;
	}

	return num;
}
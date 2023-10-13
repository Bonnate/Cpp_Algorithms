#include <iostream>

using namespace std;

static bool primeArr[1001];
static int primes[1001];

int isPrime(int x);
void divide(int x);

int main()
{
	for (int i = 0; i < 1001; ++i)
		primes[i] = primeArr[i] = 0;

	int N;
	scanf_s("%d", &N);

	printf("%d! = ", N);

	for (int i = 2; i <= N; ++i)
		divide(i);

	for (int i = 2; i <= N; ++i)
		if (primeArr[i])
			printf("%d ", primes[i]);
}

void divide(int x)
{
	int primeIdx = isPrime(x);

	if (primeIdx == -1) // 소수가 맞음
	{
		++primes[x];
	}
	else if (x >= 2) // 소수가 아닌경우, 나누기
	{
		divide(x / primeIdx);
		divide(primeIdx);
	}
}

int isPrime(int x)
{
	// 이미 소수로 등록되어있다면, 즉시 리턴
	if (primeArr[x])
		return -1;

	// 해당 값으로 나눌것이 있어 소수가 아님
	for (int i = 2; i <= sqrt(x); ++i)
		if (x % i == 0)
			return i;

	// 소수를 검출하지 못한경우, x는 소수가 맞음
	primeArr[x] = true;
	return -1;
}
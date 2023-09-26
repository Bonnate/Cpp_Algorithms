#include <iostream>

/*
int main()
{
	int N; // 입력값
	int sum = 0; // 총 합
	queue<int> properDivisors; // 진약수 큐

	scanf_s("%d", &N);

	for (int i = 1; i <= N / 2; ++i)
		if (N % i == 0)
		{
			properDivisors.push(i);
			sum += i;
		}

	// 마지막 값을 제외하고 + 포맷으로 출력
	while (properDivisors.size() > 1)
	{
		printf("%d + ", properDivisors.front());
		properDivisors.pop();
	}

	// 마지막 값은 = 포맷과 총 합 출력
	printf("%d = %d", properDivisors.front(), sum);
	properDivisors.pop();
}
*/

int main()
{
	int N; // 입력값
	int sum = 1; // 총 합

	scanf_s("%d", &N);

	printf("%d", 1);
	for (int i = 2; i <= N / 2; ++i)
		if (N % i == 0)
		{
			printf(" + %d", i);
			sum += i;
		}

	printf(" = %d", sum);
}
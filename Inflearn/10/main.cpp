#include <iostream>

int digit_sum(int x);

int main()
{
	int digitSumMax = INT_MIN;
	int answer = 0;

	int N, numInput;
	scanf_s("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &numInput);

		int digitSum = digit_sum(numInput);

		if (digitSum == digitSumMax)
			answer = answer > numInput ? answer : numInput;
		else if (digitSum > digitSumMax)
		{
			answer = numInput;
			digitSumMax = digitSum;
		}
	}

	printf("%d", answer);
}

int digit_sum(int x)
{
	int sum = 0;

	while (1)
	{
		sum += x % 10;
		x /= 10;

		if (x == 0)
			return sum;
	}
}
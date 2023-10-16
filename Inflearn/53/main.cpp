#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	stack<int> numbers;

	int N, K;
	scanf_s("%d %d", &N, &K);

	int quotient = 0, remainder = N;

	if (N == K)
	{
		printf("10");
		return 0;
	}
	else
		while (1)
		{
			quotient = N / K;
			remainder = N % K;

			N = quotient;

			// 나머지 값 삽입
			numbers.push(remainder);

			if (N < K)
			{
				if (N != 0)
					if (N < 10)
						printf("%d", N);
					else
						printf("%c", 'A' + N - 10);

				break;
			}
		}

	while (!numbers.empty())
	{
		int number = numbers.top();

		if (number < 10)
			printf("%d", number);
		else
			printf("%c", 'A' + number - 10);

		numbers.pop();
	}
}
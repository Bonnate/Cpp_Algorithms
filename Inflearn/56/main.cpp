#include <iostream>

void printNumber(int n)
{
	if (n > 1)
	{
		printNumber(n - 1);
	}

	printf("%d ", n);
}

int main()
{
	int N;
	scanf_s("%d", &N);

	printNumber(N);
}
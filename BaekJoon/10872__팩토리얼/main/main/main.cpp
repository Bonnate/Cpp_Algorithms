#include <stdio.h>

int func(int n)
{
	if (n < 1) return 1;
	
	return func(n - 1) * n;
}

int main()
{
	int N;

	scanf_s("%d", &N);

	printf("%d", func(N));
}


#include <iostream>

void binary(int n)
{
	if (n == 0)
		return;
	else if (n == 1)
	{
		printf("%d", 1);
	}
	else
	{
		binary(n / 2);
		printf("%d", n % 2);
	}
}

int main()
{
	int N;
	scanf_s("%d", &N);

	binary(N);
}
#include <stdio.h>
int main()
{
	int n, i;
	bool b = 1;
	scanf("%d", &n);
	if (n == 1) return 0;
	while (b)
	{
		b = 0;
		for (i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				b = 1;
				n /= i;
				printf("%d\n", i);
				break;
			}
		}
	}
	printf("%d", n);
}
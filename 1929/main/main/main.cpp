#include <stdio.h>

int main()
{
	int m, n, i;
	bool b;

	scanf_s("%d %d", &m, &n);

	if (m == 1) m = 2;

	for (; m <= n; ++m)
	{
		b = 0;

		for (i = 2; i * i <= m; ++i)
		{
			if (m % i == 0)
			{
				b = 1;
				break;
			}
		}

		if (!b) printf("%d\n", m);
	}
}
#include <iostream>

int main()
{
	int N;
	scanf_s("%d", &N);

	int bits = pow(2, N) - 1;

	for (int i = bits; i > 0; --i)
	{
		for (int j = N; j >= 0; --j)
		{
			int bit = 1 << j;

			if (i & bit)
				printf("%d ", N - j);
		}

		printf("\n");
	}
}
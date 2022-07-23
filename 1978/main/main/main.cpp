#include <iostream>

int main()
{
	int n, input, ans;

	scanf_s("%d", &n);

	ans = n;

	while (n--)
	{
		scanf_s("%d", &input);
		if (input == 1)
		{
			--ans;
			continue;
		}

		for (int i = 2; i * i <= input; ++i)
		{
			if (input % i == 0)
			{
				--ans;
				break;
			}
		}
	}

	printf("%d", ans);
}
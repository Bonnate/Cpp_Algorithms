#include <iostream>
#include <string>

int main()
{
	char input[9];

	int digit = 1;
	int val = 0;

	int c = 0, h = 0;

	scanf_s("%s", input, sizeof(input));

	for (int i = 0; i < input[i] != '\0'; ++i)
		if (input[i] == 'C')
		{
			for (int j = 1; ; ++i)
			{
				if (input[j + i] == 'H')
					break;

				c = c * 10 + input[j + i] - '0';
			}

			for (int j = 2; ; ++i)
			{
				if (input[j + i] == '\0')
					break;

				h = h * 10 + input[j + i] - '0';
			}
		}

	if (c == 0)
		c = 1;
	if (h == 0)
		h = 1;

	printf("%d", c * 12 + h);
}
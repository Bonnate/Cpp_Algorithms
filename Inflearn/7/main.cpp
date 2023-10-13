#include <iostream>

int main()
{
	char input[101];
	scanf_s("%100[^\n]", input, sizeof(input));

	for (int i = 0; input[i] != '\0'; ++i)
		if (input[i] != ' ')
			printf("%c", input[i] <= 'Z' ? input[i] + 32 : input[i]);

	return 0;
}
#include <iostream>
#include <cstring>

int main()
{
	char input[31];
	scanf_s("%s", input, sizeof(input));

	int left = 0, right = 0;
	int inputLen = strlen(input);

	// 괄호의 개수가 홀수라면?
	if (inputLen % 2 == 1)
	{
		printf("NO");
		return 0;
	}

	// 괄호의 양 끝이 잘못되었다면?
	if (input[0] == ')' || input[inputLen - 1] == '(')
	{
		printf("NO");
		return 0;
	}

	for (int i = 0; input[i] != '\0'; ++i)
		if (input[i] == '(')
			++left;
		else if (input[i] == ')')
			++right;

	printf("%s", left == right ? "YES" : "NO");
}
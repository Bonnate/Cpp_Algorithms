#include <iostream>
#include <stack>

using namespace std;
int main()
{
	char str[31];
	scanf_s("%s", &str, sizeof(str));
	stack<bool> stack;

	for (int i = 0; i < str[i] != '\0'; ++i)
	{
		bool isOpen = str[i] == '(';

		if (!stack.empty() && stack.top() && !isOpen)
		{
			stack.pop();
			continue;
		}

		stack.push(isOpen);
	}

	printf("%s", stack.size() > 0 ? "NO" : "YES");
}
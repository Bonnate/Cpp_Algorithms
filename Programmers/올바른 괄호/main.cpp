#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<bool> st;
	for (int i = 0; i < s[i] != '\0'; ++i)
	{
		bool isOpen = s[i] == '(';

		if (!st.empty() && st.top() && !isOpen)
		{
			st.pop();
			continue;
		}

		st.push(isOpen);
	}

	bool answer = st.empty();

	return answer;
}

int main()
{
	cout << solution("");
}
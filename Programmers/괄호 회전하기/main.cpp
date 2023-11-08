#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		s.push_back(s[0]);
		s.erase(0, 1);

		stack<char> st;
		for (char c : s)
		{
			if (st.empty())	st.push(c);
			else
			{
				if (st.top() == '{' && c == '}') st.pop();
				else if (st.top() == '[' && c == ']') st.pop();
				else if (st.top() == '(' && c == ')') st.pop();
				else st.push(c);
			}
		}

		if (st.empty())
			++answer;
	}

	return answer;
}

int main()
{
	//solution("{}(){}");
	//solution("}]()[{");
	//solution("[)(]");
	solution("}}}");
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) {
	unordered_map<char, int> m1, m2;

	for (char c : X)
		++m1[c];

	for (char c : Y)
		++m2[c];

	string answer = "";

	for (int i = 9; i >= 0; --i)
	{
		char c = '0' + i;

		if (m1.find(c) != m1.end() && m2.find(c) != m2.end())
		{
			int cnt = min(m1[c], m2[c]);

			for (int i = 0; i < cnt; ++i)
				answer.push_back(c);
		}
	}

	// 비어있는경우?
	if (answer.empty())
		return "-1";

	// 가장 앞자리가 0인경우?
	if (answer[0] == '0')
		return "0";

	return answer;
}

int main(int argc, const char* argv[]) {
	solution("12321", "42531");

	return 0;
}
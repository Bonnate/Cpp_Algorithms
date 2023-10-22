#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	unordered_set<string> s;
	int r = 1, id = 0;
	bool iskilled = false;

	string lastWord = words[0];
	lastWord[lastWord.length() - 1] = words[0][0];

	for (string word : words)
	{
		if (++id == n + 1)
			id = 1, ++r;

		if (lastWord[lastWord.length() - 1] != word[0])
		{
			iskilled = true;
			break;
		}

		if (s.find(word) == s.end()) {
			s.insert(word);
			lastWord = word;
		}
		else
		{
			iskilled = true;
			break;
		}
	}

	if (iskilled == false)
		return vector<int>{ 0, 0 };

	vector<int> answer{ id, r };
	return answer;
}

int main()
{
	vector<int> v = solution(2, { "hello", "one", "even", "never", "now", "world", "draw" });
	cout << v[0] << " " << v[1];
}
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
	unordered_map<string, int> m;
	for (int i = 0; i < name.size(); ++i)
		m[name[i]] = yearning[i];

	vector<int> answer = vector<int>(photo.size(), 0);
	for (int i = 0; i < photo.size(); ++i)
		for (string s : photo[i])
		{
			if (m.find(s) != m.end())
				answer[i] += m[s];
		}

	return answer;
}

int main()
{
	//solution(
	//	{ "may", "kein", "kain", "radi" },
	//	{ 5, 10, 1, 3 },
	//	{ {"may", "kein", "kain", "radi"}, { "may", "kein", "brin", "deny" }, { "kon", "kain", "may", "coni" } });

	solution(
		{ "kali", "mari", "don" },
		{ 11, 1, 55 },
		{ {"kali", "mari", "don"}, { "pony", "tom", "teddy" }, { "con", "mona", "don" } }
	);
}
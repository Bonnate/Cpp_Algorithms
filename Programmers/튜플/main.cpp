#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(string s) {
	s.erase(0, 1);
	s.erase(s.size() - 1, 1);

	priority_queue<pair<int, vector<string>>> q;

	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '{')
		{
			++i;
			vector<string> v;
			string builder;

			for (; i < s.size(); ++i)
				if (s[i] == '}')
				{
					v.push_back(builder);
					q.push({ -(int)v.size(), v });
					break;
				}
				else if (s[i] == ',')
				{
					v.push_back(builder);
					builder.erase(0);
				}
				else
				{
					builder.push_back(s[i]);
				}
		}

	set<string> set;
	vector<int> answer;
	while (!q.empty())
	{
		vector<string> v = q.top().second;
		q.pop();

		for (int i = 0; i < v.size(); ++i)
			if (set.find(v[i]) == set.end())
			{
				answer.push_back(stoi(v[i]));
				set.insert(v[i]);
			}
			else
				continue;
	}

	return answer;
}

int main()
{
	//solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
	//solution("{{20,111},{111}}");
	//solution("{{123}}");
	//solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
}
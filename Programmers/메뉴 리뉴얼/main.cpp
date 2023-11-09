#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

unordered_map<string, int> m;
int sel[10];

void DFS(int l, int s, int n, string order)
{
	if (l == n)
	{
		string s;
		for (int i = 0; i < n; ++i)
			s.push_back(order[sel[i]]);

		sort(s.begin(), s.end());
		++m[s];
	}
	else
	{
		for (int i = s; i < order.size(); ++i)
		{
			sel[l] = i;
			DFS(l + 1, i + 1, n, order);
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (int n : course)
	{
		for (string order : orders)
			DFS(0, 0, n, order);

		priority_queue<pair<int, string>> q;
		for (pair<string, int> p : m)
			if (p.second >= 2)
				q.push({ p.second, p.first });

		if (!q.empty())
		{
			int max = q.top().first;
			answer.push_back(q.top().second);
			q.pop();

			while (!q.empty())
			{
				if (max != q.top().first)
					break;

				answer.push_back(q.top().second);
				q.pop();
			}
		}

		m.clear();
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	//solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2, 3, 4 });
	//solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2, 3, 5 });
	solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
}
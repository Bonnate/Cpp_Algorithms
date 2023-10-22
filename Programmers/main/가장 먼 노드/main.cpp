#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> dist;
vector<vector<int>> map;
vector<bool> visit;

int solution(int n, vector<vector<int>> edge) {
	dist = vector<int>(n + 1);
	visit = vector<bool>(n + 1);
	map = vector<vector<int>>(n + 1, vector<int>());

	for (int i = 0; i < edge.size(); ++i)
	{
		map[edge[i][0]].push_back(edge[i][1]);
		map[edge[i][1]].push_back(edge[i][0]);
	}

	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		for (int i = 0; i < map[pos].size(); ++i)
		{
			if (!visit[map[pos][i]])
			{
				visit[map[pos][i]] = true;
				q.push(map[pos][i]);
				dist[map[pos][i]] = dist[pos] + 1;
			}
		}
	}

	int maxV = 0;
	for (int i = 1; i <= n; ++i)
		maxV = max(maxV, dist[i]);

	int answer = 0;
	for (int i = 1; i <= n; ++i)
		if (dist[i] == maxV)
			++answer;

	return answer;
}

int main()
{
	cout << solution(3, vector<vector<int>>{ { 1, 2}, { 1, 3 }});
}
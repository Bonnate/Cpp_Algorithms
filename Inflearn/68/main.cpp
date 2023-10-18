#include <iostream>
#include <vector>
using namespace std;

static vector<pair<int, int>>* graph;
static vector<bool> visited;
static int minCost = INT_MAX;
int N;

void DFS(int v = 0, int cost = 0)
{
	// v에 방문
	visited[v] = true;

	// 지금까지 누적된 비용이 min보다 높다면 리턴
	if (cost > minCost)
		return;

	// 목적지에 도착
	if (v == N - 1)
		minCost = minCost > cost ? cost : minCost;
	else
		for (int i = 0; i < graph[v].size(); ++i)
			if (!visited[graph[v][i].first])
			{
				// v에 방문하기
				DFS(graph[v][i].first, cost + graph[v][i].second);
				visited[graph[v][i].first] = false;
			}
}

int main()
{
	int M;
	scanf_s("%d %d", &N, &M);

	graph = new vector<pair<int, int>>[N];
	visited = vector<bool>(N, false);

	int f, t, c; // from, to, cost
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &c);

		// 그래프에 목적지와 비용 삽입
		graph[f - 1].push_back({ t - 1, c });
	}

	DFS();

	printf("%d", minCost);
}
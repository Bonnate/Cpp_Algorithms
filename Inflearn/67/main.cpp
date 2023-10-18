#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;
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
		for (int i = 0; i < N; ++i)
			if (!visited[i] && graph[v][i] >= 0)
			{
				// v에 방문하기
				DFS(i, cost + graph[v][i]);
				visited[i] = false;
			}
}

int main()
{
	int M;
	scanf_s("%d %d", &N, &M);

	graph = vector<vector<int>>(N, vector<int>(N, -1));
	visited = vector<bool>(N, false);

	int f, t, c; // from, to, cost
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &c);
		graph[f - 1][t - 1] = c;
	}

	DFS();

	printf("%d", minCost);
}
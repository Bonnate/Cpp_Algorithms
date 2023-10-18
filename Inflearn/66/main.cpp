#include <iostream>
#include <vector>
using namespace std;

static int cnt = 0;
bool* visited;

void DFS(vector<int> map[], int N, int v)
{
	visited[v] = true;

	if (v == N)
		++cnt;
	else
		for (int i = 0; i < map[v].size(); ++i)
			if (!visited[map[v][i]])
			{
				DFS(map, N, map[v][i]);
				visited[map[v][i]] = false;
			}
}

int main()
{
	int N, M, f, t;
	scanf_s("%d %d", &N, &M);
	vector<int>* map = new vector<int>[N + 1];
	visited = new bool[N + 1];

	for (int i = 1; i <= N; ++i)
		visited[i] = false;

	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &f, &t);
		map[f].push_back(t);
	}

	DFS(map, N, 1);

	printf("%d", cnt);
}
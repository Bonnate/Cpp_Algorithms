#include <iostream>
#include <vector>
using namespace std;

static int N, M, cnt = 0;
static vector <vector<bool>> arr;
static vector <bool> visited;

void DFS(int v)
{
	// 방문 TRUE
	visited[v] = true;

	// v(방문지)가 N - 1(마지막 노드)이라면?
	if (v == N - 1)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			// 더 방문할곳이 있다면?
			if (arr[v][i] == 1 && visited[i] == 0)
			{
				DFS(i); // 해당 구역에 더 찾아가기 (DFS)
				visited[i] = false; // 해당 구역에서 빠져나오면, 해당 구역 방문은 false로 전환
			}
		}
	}
}
int main()
{
	scanf_s("%d %d", &N, &M);

	arr = vector <vector<bool>>(N, vector<bool>(N, false));
	visited = vector<bool>(N, false);

	int f, t; // from, to
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &f, &t);

		arr[f - 1][t - 1] = true;
	}

	// 0번(맨 처음)부터 방문 시작
	DFS(0);

	printf("%d", cnt);
}
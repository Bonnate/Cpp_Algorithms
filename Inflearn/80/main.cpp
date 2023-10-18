#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int to;
	int weight;

	Edge(int to, int weight) : to(to), weight(weight) {}

	bool operator < (const Edge& ref) const
	{
		return weight > ref.weight;
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<pair<int, int>> graph[21];
	vector<int> dist(21, INT_MAX);

	int N, M, f, t, w;
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		graph[f].push_back({ t, w });
	}

	// 1번 간선에서 시작
	q.push(Edge(1, 0));
	dist[1] = 0;

	while (!q.empty())
	{
		int current = q.top().to;
		int weight = q.top().weight;
		q.pop();

		// 해당 정점으로 갈 때, 이미 더 적은 비용의 거리가 있다면 리턴
		if (weight > dist[current])
			continue;

		// current 정점으로부터 뻗어나갈 수 있는 모든 방향으로 방문하기
		for (int i = 0; i < graph[current].size(); ++i)
		{
			// 다음 노드의 번호와 누적 가중치 가져오기
			int next = graph[current][i].first;
			int nextWeight = weight + graph[current][i].second;

			// 해당 노드까지의 비용이 저장된 비용보다 적다면?
			if (dist[next] > nextWeight)
			{
				// 비용 갱신
				dist[next] = nextWeight;

				// 해당 노드 방문
				q.push(Edge(next, nextWeight));
			}
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		printf("%d : ", i);

		if (dist[i] == INT_MAX)
			printf("impossible");
		else
			printf("%d", dist[i]);

		printf("\n");
	}
}
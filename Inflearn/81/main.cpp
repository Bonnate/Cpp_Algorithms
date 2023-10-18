#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;

	Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

	bool operator < (const Edge& ref) const
	{
		return weight > ref.weight;
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<Edge> edges; // 간선 정보를 담는 벡터
	vector<int> dist; // 가중치 누적

	int N, M, f, t, w;
	scanf_s("%d %d", &N, &M);

	dist = vector<int>(N + 1, INT_MAX);

	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		edges.push_back({ f, t, w });
	}

	scanf_s("%d %d", &f, &t);
	dist[f] = 0;

	for (int i = 1; i < N; ++i) // 간선의 개수를 1개부터 증가시켜 지속적으로 갱신
		for (int j = 0; j < edges.size(); ++j) // 모든 간선을 검사
		{
			int from = edges[j].from; // 현재 위치한 곳
			int to = edges[j].to; // 다음으로 갈 곳
			int weight = edges[j].weight; // 다음으로 가기 위한 가중치

			// 만약 현재 위치의 가중치가 INT_MAX가 아니면서(다른 간선에 의해 현재 위치로 옴)
			// 현재까지의 가중치 + 다음으로 가기 위한 가중치가 저장된 가중치보다 작다면?
			if (dist[from] != INT_MAX && dist[from] + weight < dist[to])
				dist[to] = dist[from] + weight; // 가중치 갱신
		}

	// 모든 간선 정보를 한번씩 검사하여 음의 사이클이 존재하는지 확인
	for (int i = 0; i < edges.size(); ++i)
	{
		int from = edges[i].from;
		int to = edges[i].to;
		int weight = edges[i].weight;

		// 현재까지의 가중치 + 다음으로 가기 위한 가중치가 다음 위치의 저장된 가중치보다 작다면 음의 사이클이 존재
		if (dist[from] != INT_MAX && dist[from] + weight < dist[to])
		{
			printf("-1");
			exit(0);
		}
	}

	printf("%d", dist[t]);
}
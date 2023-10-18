#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 노드에 방문 하였는지 검사
bool linked[101];

int main()
{
	vector<vector<pair<int, int>>> graph; // 그래프의 간선 정보 (도착지, 비용)
	priority_queue<pair<int, int>> q; // 우선순위 큐
	int cnt = 0;

	int V, E, sum = 0;
	scanf_s("%d %d", &V, &E);

	graph = vector<vector<pair<int, int>>>(V + 1);

	int f, t, w;
	for (int i = 0; i < E; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		graph[f].push_back({ t, w });
		graph[t].push_back({ f, w });
	}

	q.push({ 0, 1 }); // 가중치가 0인 1로 가는 간선으로 시작

	while (cnt != V)
	{
		// 가장 가중치가 낮은 정보를 가져오기
		pair<int, int> data = q.top();
		q.pop();

		int weight = -data.first; // -data.first로 가중치 원본 가져오기
		int to = data.second; // 목적지

		// 이미 방문했던 노드라면 컨티뉴
		if (linked[to])
			continue;

		// 처음 방문하는 노드라면 진행

		sum += weight;
		++cnt;
		linked[to] = true;

		// 현재 위치에서 갈 수 있는 모든 간선 정보를 삽입
		for (int i = 0; i < graph[to].size(); ++i)
			q.push({ -graph[to][i].second, graph[to][i].first });
	}

	printf("%d", sum);
}
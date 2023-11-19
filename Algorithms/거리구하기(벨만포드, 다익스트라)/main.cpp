#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// 간선 정보
struct Edge1 {
	int from, to, weight;
};

int bellman_ford(int N, vector<vector<int>> road, int K) {
	vector<Edge1> edges;
	vector<int> dist(N + 1, INT_MAX);

	// 그래프 정보 초기화 (무방향 그래프로 양측 노드에 삽입)
	for (vector<int> r : road) {
		edges.push_back({ r[0], r[1], r[2] });
		edges.push_back({ r[1], r[0], r[2] });
	}

	// 시작 노드의 거리는 0
	dist[1] = 0;

	// 벨만-포드 알고리즘
	// 모든 노드에 대한 가장 짧은 경로는 노드의 수보다 하나 작은 간선의 수(N-1)로 이루어지기에 N-1번 반복
	for (int i = 0; i < N - 1; ++i)
	{
		for (Edge1 edge : edges)
		{
			int from = edge.from;
			int to = edge.to;
			int weight = edge.weight;

			// 아직 다른 간선에 의해 비용이 계산되지 않은경우에는 무시
			if (dist[from] == INT_MAX)
			{
				printf("%d은 아직 계산되지 않음!\n", from);
				continue;
			}

			// 현재 위치의 비용(dist[from]) + 다음 위치까지의 비용(weight)이 저장된 비용(dist[to])보다 작으면 갱신
			if (dist[to] > dist[from] + weight)
			{
				printf("%d->%d은 %d에서 %d로 갱신!\n", from, to, dist[to], dist[from] + weight);
				dist[to] = dist[from] + weight;
			}
		}
		cout << endl;
	}

	// 정답 구하기
	int answer = 0;
	for (int i = 1; i <= N; ++i)
		if (dist[i] <= K)
			++answer;

	return answer;
}

// 간선 정보
struct Edge2 {
	int to, weight;
};

int dijkstra(int N, vector<vector<int>> road, int K) {
	vector<vector<Edge2>> graph(N + 1);
	vector<int> dist(N + 1, INT_MAX);

	// 그래프 정보 초기화 (양방향)
	for (vector<int> r : road) {
		int from = r[0];
		int to = r[1];
		int weight = r[2];
		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}

	// 우선순위 큐를 이용한 다익스트라 알고리즘
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[1] = 0; // 시작 노드의 거리는 0
	pq.push({ 0, 1 }); // {거리, 노드} 쌍을 우선순위 큐에 삽입

	while (!pq.empty()) {
		int current_distance = pq.top().first;
		int current_node = pq.top().second;
		pq.pop();

		printf("현재위치: %d, 누적비용: %d\n", current_node, current_distance);

		// 현재 노드에서 갈 수 있는 모든 노드들에 대해 최단 거리 갱신
		for (Edge2& e : graph[current_node])
		{
			int next_node = e.to;
			int weight = e.weight;

			printf("다음 노드: %d, 비용: %d\n", next_node, weight);

			if (dist[next_node] > current_distance + weight)
			{
				dist[next_node] = current_distance + weight;
				pq.push({ dist[next_node], next_node });

				printf("노드 갱신: %d, 비용: %d\n", next_node, dist[next_node]);
			}
		}
	}

	// 정답 구하기
	int answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] <= K)
			++answer;

		cout << dist[i] << " ";
	}

	return answer;
}

int main()
{
	//bellman_ford(5, { {1, 2, 1}, { 2,3,3 }, { 5,2,2 }, { 1,4,2 }, { 5,3,1 }, { 5,4,2 } }, 3);
	//bellman_ford(6, { {1, 2, 1}, { 1,3,2 }, { 2,3,2 }, { 3,4,3 }, { 3,5,2 }, { 3,5,3 }, { 5,6,1 } }, 4);

	dijkstra(5, { {1, 2, 1}, { 2,3,3 }, { 5,2,2 }, { 1,4,2 }, { 5,3,1 }, { 5,4,2 } }, 3);
	//dijkstra(6, { {1, 2, 1}, { 1,3,2 }, { 2,3,2 }, { 3,4,3 }, { 3,5,2 }, { 3,5,3 }, { 5,6,1 } }, 4);
}
#include <iostream>
#include <queue>
using namespace std;

vector<int> map[20]; // 인접 리스트
bool visited[20];

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	int f, t; // from, to
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &f, &t);
		map[f - 1].push_back(t - 1);
	}

	queue<int> visit;
	visit.push(0); // 0번 노드부터 시작
	visited[0] = true;
	int distance[20];

	distance[0] = 0;

	while (!visit.empty())
	{
		// 현재 위치를 가져오기
		int currentNode = visit.front();
		visit.pop();

		for (int i = 0; i < map[currentNode].size(); ++i)
		{
			// 해당 노드를 방문하지 않았다면?
			if (!visited[map[currentNode][i]])
			{
				// 해당 노드를 방문
				visited[map[currentNode][i]] = true;

				// 방문 거리는 현재 노드의 누적 거리 + 1
				distance[map[currentNode][i]] = distance[currentNode] + 1;

				// 큐에 삽입
				visit.push(map[currentNode][i]);
			}
		}
	}

	for (int i = 0; i < N; ++i)
		printf("%d : %d\n", i + 1, distance[i]);
}
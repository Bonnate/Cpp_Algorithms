#include <iostream>
#include <queue>
using namespace std;

// Union-Find에서 집합 정보를 저장할 배열
int arr[1001];

// Find
int Find(int n)
{
	if (n == arr[n]) return n;
	else return arr[n] = Find(arr[n]);
}

// Union
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		arr[a] = b;
}

int main()
{
	int N, M, f, t, w, res = 0;
	scanf_s("%d %d", &N, &M);

	// 우선순위 큐를 사용하여 더욱 효율적으로 정렬
	priority_queue<pair<int, pair<int, int>>> q; // -가중치, 출발, 도착
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		q.push({ -w, {f, t} });
	}

	// 집합 정보 초기화
	for (int i = 1; i <= N; ++i)
		arr[i] = i;

	// 모든 간선 정보를 사용
	while (!q.empty())
	{
		// 가장 비용이 낮은 간선 정보를 가져오기
		pair<int, pair<int, int>> data = q.top();
		q.pop();

		// 정보 추출
		int weight = -data.first;
		int from = data.second.first;
		int to = data.second.second;

		// 간선의 집합 정보 가져오기
		int a = Find(from);
		int b = Find(to);

		// 서로 다른 집합이라면?
		if (a != b)
		{
			// 가중치를 합하고, 결합
			res += weight;
			Union(from, to);
		}
	}

	printf("%d", res);
}
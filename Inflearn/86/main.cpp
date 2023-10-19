#include <iostream>
#include <vector>
using namespace std;

int N, M, minRes = INT_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> pizza;

int select[12];

void DFS(int l, int s)
{
	// 피자집 M개를 다 뽑았다면?
	if (l == M)
	{
		// 도시 거리
		int cityDistance = 0;

		// 모든 집을 계산
		for (int i = 0; i < home.size(); ++i)
		{
			int pizzaDistance = INT_MAX;

			for (int j = 0; j < M; ++j)
			{
				// 피자집으로부터 거리를 구하기
				int dist = abs(home[i].first - pizza[select[j]].first) + abs(home[i].second - pizza[select[j]].second);

				// 피자집과 집의 최소 거리를 갱신
				pizzaDistance = min(pizzaDistance, dist);
			}

			// 도시 거리 더하기
			cityDistance += pizzaDistance;
		}

		// 도시 최소 거리 구하기
		minRes = min(minRes, cityDistance);
	}
	else
	{
		// pizza 중에서 M개를 뽑기 (DFS로 M개를 뽑기)
		for (int i = s; i < pizza.size(); ++i)
		{
			select[l] = i;
			DFS(l + 1, i + 1);
		}
	}
}

int main()
{
	scanf_s("%d %d", &N, &M);

	int input;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf_s("%d", &input);

			if (input == 1)
				home.push_back({ i, j });
			else if (input == 2)
				pizza.push_back({ i, j });
		}
	}

	DFS(0, 0);

	printf("%d", minRes);
}
#include <iostream>
#include <queue>
using namespace std;

bool visited[10001];
int dist[10001];

// 주어진 조건에 맞게 배열을 선언
int d[3] = { 1, -1, 5 };

int main()
{
	int S, E;
	scanf_s("%d %d", &S, &E);

	queue<int> q;

	q.push(S);
	visited[S] = true;

	while (!q.empty())
	{
		int currentPos = q.front();
		q.pop();

		if (currentPos == E)
		{
			printf("%d", dist[currentPos]);
			break;
		}

		for (int i = 0; i < 3; ++i)
		{
			if (!visited[currentPos + d[i]])
			{
				visited[currentPos + d[i]] = true;
				dist[currentPos + d[i]] = dist[currentPos] + 1;
				q.push(currentPos + d[i]);
			}
		}
	}
}
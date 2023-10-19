#include <iostream>
#include <queue>
using namespace std;

int maze[7][7];
int cnt[7][7];

int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };

int main()
{
	for (int i = 0; i < 7; ++i)
		for (int j = 0; j < 7; ++j)
		{
			scanf_s("%d", &maze[i][j]);
			cnt[i][j] = INT_MAX;
		}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	cnt[0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		maze[x][y] = 1;

		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || yy < 0 || xx == 7 || yy == 7)
				continue;

			if (maze[xx][yy] == 0)
			{
				// 해당 위치에 도착하는경우, 가장 먼저 도착하는것이기에 비교연산을 할 필요는 없음 !
				cnt[xx][yy] = cnt[x][y] + 1;

				q.push({ xx, yy });
			}
		}
	}

	printf("%d", cnt[6][6] == INT_MAX ? -1 : cnt[6][6]);
}
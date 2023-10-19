#include <iostream>
#include <queue>
using namespace std;

bool island[21][21];

// 각 방향을 더욱 효율적으로 계산하기 위해 선언
int dx[8]{ -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8]{ -1, -1, -1, 0, 0, 1, 1, 1 };

int main()
{
	int N;
	scanf_s("%d", &N);

	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf_s("%d", &island[i][j]);

	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// 각 섬을 검사하여 섬이라면 인접한 섬들을 계산
			if (island[i][j] == 1)
			{
				// 섬을 시작하면서 개수를 1 더하기
				++cnt;

				q.push({ i,j });
				island[i][j] = 0;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 8; ++k)
					{
						int xx = x + dx[k];
						int yy = y + dy[k];

						// 계산된 거리가 범위를 벗어난다면 고려하지 않아야 함
						if (xx < 0 || yy < 0 || xx > N || yy > N)
							continue;

						// 방문 가능한 모든 섬 위치를 삽입
						if (island[xx][yy] == 1)
						{
							island[xx][yy] = 0;
							q.push({ xx, yy });
						}
					}
				}
			}
		}
	}

	printf("%d", cnt);
}
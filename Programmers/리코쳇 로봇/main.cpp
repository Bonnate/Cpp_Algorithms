#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };

int solution(vector<string> board) {
	int width = board[0].size();
	int height = board.size();

	// 큐
	stack<pair<int, int>> q;

	// 거리를 저장
	vector<vector<int>> v(vector<vector<int>>(height, vector<int>(width, 999)));

	// 시작, 도착 지점 저장
	pair<int, int> start{ -1, -1 }, end{ -1, -1 };
	for (int i = 0; i < height; ++i)
		if (start.first != -1 && end.first != -1)
			break;
		else
			for (int j = 0; j < width; ++j)
				if (board[i][j] == 'R')
					start = { i, j };
				else if (board[i][j] == 'G')
					end = { i, j };

	q.push(start);
	v[start.first][start.second] = 0;
	while (!q.empty())
	{
		int x = q.top().second;
		int y = q.top().first;
		q.pop();

		printf("현재위치: %d %d\n", y, x);

		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			// 상하좌우 방향을 한칸 이상 갈 수 있는지 확인
			if (xx == -1 || yy == -1 || xx == width || yy == height || board[yy][xx] == 'D')
			{
				printf("%d %d에서 %d %d로 갈 수 없음!\n", y, x, yy, xx);
				continue;
			}

			// 갈 수 있는 방향에서 최대로 이동
			int xxx = x;
			int yyy = y;
			while (true)
			{
				xxx += dx[i];
				yyy += dy[i];

				if (xxx == -1 || yyy == -1 || xxx == width || yyy == height || board[yyy][xxx] == 'D')
				{
					xxx -= dx[i];
					yyy -= dy[i];

					// 기존에 방문한 거리보다 짧은 거리에 도달했다면?
					// 해당 위치를 짧은 거리로 다시 갱신하여 다시 뻗어나가기
					if (v[yyy][xxx] > v[y][x] + 1)
					{
						q.push({ yyy, xxx });
						printf("%d %d에서 %d %d로 이동!\n", y, x, yyy, xxx);
						v[yyy][xxx] = v[y][x] + 1;
					}

					break;
				}
			}
		}
	}

	return v[end.first][end.second] == 999 ? -1 : v[end.first][end.second];
}

int main() {
	//cout << solution({
	//	"...D..R",
	//	".D.G...",
	//	"....D.D",
	//	"D....D.",
	//	"..D...." });
	cout << solution({
		".D.R",
		"....",
		".G..",
		"...D" });
}
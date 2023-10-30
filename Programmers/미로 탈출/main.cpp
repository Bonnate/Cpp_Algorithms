#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, 1, -1 };

vector<vector<int>> dist;

int height;
int width;

bool levelTriggered = false;

bool BFS(vector<string> maps, pair<int, int> start, char find)
{
	queue<pair<int, int>> q;
	q.push(start);
	vector<vector<bool>> visit = vector<vector<bool>>(height, vector<bool>(width, false));
	visit[start.first][start.second] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (xx == -1 || yy == -1 || yy == height || xx == width || visit[yy][xx] || maps[yy][xx] == 'X')
				continue;

			dist[yy][xx] = dist[y][x] + 1;
			visit[yy][xx] = true;
			q.push({ yy, xx });

			if (maps[yy][xx] == find)
				return true;
		}
	}

	return false;
}

int solution(vector<string> maps) {
	height = maps.size();
	width = maps[0].length();

	dist = vector<vector<int>>(height, vector<int>(width, false));

	pair<int, int> start{ -1,-1 }, end{ -1, -1 }, lever{ -1, -1 };

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (start.first != -1 && end.first != -1 && lever.first != -1)
				break;
			else if (maps[i][j] == 'S')
				start = { i, j };
			else if (maps[i][j] == 'E')
				end = { i, j };
			else if (maps[i][j] == 'L')
				lever = { i, j };

	if (!BFS(maps, start, 'L'))
		return -1;

	if (BFS(maps, lever, 'E'))
		return dist[end.first][end.second];
	else
		return -1;
}

int main()
{
	int res;
	res = solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" });
	//solution({ "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO" });

	printf("%d", res);
}
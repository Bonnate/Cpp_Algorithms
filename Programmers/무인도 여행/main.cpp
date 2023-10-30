#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };

int width, height, sum;

vector<vector<bool>> visit;
vector<int> answer;

// DFS
void DFS(vector<string> maps, int food, int y, int x)
{
	sum += food;

	for (int i = 0; i < 4; ++i)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (xx == -1 || yy == -1 || xx == width || yy == height || maps[yy][xx] == 'X' || visit[yy][xx])
			continue;

		visit[yy][xx] = true;

		DFS(maps, maps[yy][xx] - '0', yy, xx);
	}
}

vector<int> solution(vector<string> maps) {
	height = maps.size();
	width = maps[0].size();

	queue<pair<int, int>> q;
	visit = vector<vector<bool>>(height, vector<bool>(width, false));

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (!visit[i][j] && maps[i][j] != 'X')
			{
				sum = 0;
				visit[i][j] = true;
				DFS(maps, maps[i][j] - '0', i, j);
				answer.push_back(sum);
			}

	sort(answer.begin(), answer.end());
	if (answer.empty())
		answer.push_back(-1);
	return answer;
}

/*
// BFS

vector<int> solution(vector<string> maps) {
	int height = maps.size();
	int width = maps[0].size();

	queue<pair<int, int>> q;
	vector<vector<bool>> v(vector<vector<bool>>(height, vector<bool>(width, false)));
	vector<int> answer;

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (maps[i][j] != 'X' && !v[i][j])
			{
				int sum = 0;
				q.push({ i, j });
				v[i][j] = true;

				while (!q.empty())
				{
					int x = q.front().second;
					int y = q.front().first;
					q.pop();

					sum += (maps[y][x] - '0');

					for (int k = 0; k < 4; ++k)
					{
						int xx = x + dx[k];
						int yy = y + dy[k];

						if (xx == -1 || yy == -1 || xx == width || yy == height || maps[yy][xx] == 'X' || v[yy][xx])
							continue;

						v[yy][xx] = true;

						q.push({ yy, xx });

						printf("{%d %d}에서 {%d %d}로 이동!\n", y, x, yy, xx);
					}
				}

				answer.push_back(sum);
			}

	sort(answer.begin(), answer.end());

	if (answer.empty())
		answer.push_back(-1);

	return answer;
}
*/

int main() {
	//solution({ "X591X","X1X5X","X231X", "1XXX1" });
	solution({	"X591X",
				"X1X5X",
				"3231X", 
				"1XXX1" });
	//solution({ "XXX","XXX","XXX" });
}
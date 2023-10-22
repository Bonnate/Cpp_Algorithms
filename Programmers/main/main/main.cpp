#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dist[100][100];

struct pos
{
	int x;
	int y;

	pos(int x, int y) :x(x), y(y) {}
};

int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };

int main()
{
	vector<vector<int>> maps = { {1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1}, {0,0,0,0,1} };
	{ {1, 0, 1, 1, 1}, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 0],[0, 0, 0, 0, 1]]

	int answer = 0;

	queue<pos> q;
	q.push({ 0, 0 });
	maps[0][0] = 0;

	while (!q.empty())
	{
		pos currentPos = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int xx = currentPos.x + dx[i];
			int yy = currentPos.y + dy[i];

			if (xx < 0 || yy < 0 || xx >= maps.size() || yy >= maps[0].size())
				continue;

			if (maps[xx][yy] == 1)
			{
				maps[xx][yy] = 0;
				dist[xx][yy] = dist[currentPos.x][currentPos.y] + 1;
				q.push({ xx, yy });
			}
		}
	}

	return answer;
}
#include <iostream>

#define _MAZE_SIZE 7

static bool maze[_MAZE_SIZE][_MAZE_SIZE];
static bool isVisited[_MAZE_SIZE][_MAZE_SIZE];
static int cnt = 0;

void DFS(int w, int d) // width, depth
{
	isVisited[w][d] = true;

	if (w == 6 && d == 6)
	{
		++cnt;
	}
	else
	{
		// 네 방향을 검사

		// 왼쪽 방향으로 갈 수 있는가?
		if (w - 1 > 0 && maze[w - 1][d] == 0 && !isVisited[w - 1][d])
		{
			DFS(w - 1, d);
			isVisited[w - 1][d] = false;
		}
		// 오른쪽 방향으로 갈 수 있는가?
		if (w + 1 < _MAZE_SIZE && maze[w + 1][d] == 0 && !isVisited[w + 1][d])
		{
			DFS(w + 1, d);
			isVisited[w + 1][d] = false;
		}
		// 위 방향으로 갈 수 있는가?
		if (d - 1 > 0 && maze[w][d - 1] == 0 && !isVisited[w][d - 1])
		{
			DFS(w, d - 1);
			isVisited[w][d - 1] = false;
		}
		// 아래 방향으로 갈 수 있는가?
		if (d + 1 < _MAZE_SIZE && maze[w][d + 1] == 0 && !isVisited[w][d + 1])
		{
			DFS(w, d + 1);
			isVisited[w][d + 1] = false;
		}
	}
}

int main()
{
	int input;
	for (int i = 0; i < _MAZE_SIZE; ++i)
		for (int j = 0; j < _MAZE_SIZE; ++j)
		{
			isVisited[i][j] = false;
			scanf_s("%d", &input);
			maze[i][j] = input;
		}

	DFS(0, 0);

	printf("%d", cnt);
}
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct node
{
	bool visited[4];
};

enum direction
{
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
};

struct visit
{
	int row;
	int col;
	direction dir;
};

vector<int> solution(vector<string> grid) {
	int row = grid.size(); // 행
	int col = grid[0].size(); // 열
	set<string> s;
	vector<int> answer;

	// 중복 방문 검사
	vector<vector<node>> v = vector<vector<node>>(row, vector<node>(col));

	queue<visit> q;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			for (int k = 0; k < 4; ++k)
			{
				// 시작 지점
				visit temp;
				temp.row = i;
				temp.col = j;
				temp.dir = (direction)k;
				q.push(temp);
				int cnt = 0;

				while (true)
				{
					visit vi = q.front();
					q.pop();

					v[vi.row][vi.col].visited[vi.dir] = true;

					++cnt;

					switch (grid[vi.row][vi.col])
					{
					case 'S':
						switch (vi.dir)
						{
						case LEFT:
							++vi.col;
							break;
						case RIGHT:
							--vi.col;
							break;
						case TOP:
							++vi.row;
							break;
						case BOTTOM:
							--vi.row;
							break;
						}
						break;
					case 'L':
						switch (vi.dir)
						{
						case LEFT:
							--vi.row;
							vi.dir = BOTTOM;
							break;
						case RIGHT:
							++vi.row;
							vi.dir = TOP;
							break;
						case TOP:
							++vi.col;
							vi.dir = LEFT;
							break;
						case BOTTOM:
							--vi.col;
							vi.dir = RIGHT;
							break;
						}
						break;
					case 'R':
						switch (vi.dir)
						{
						case LEFT:
							++vi.row;
							vi.dir = TOP;
							break;
						case RIGHT:
							--vi.row;
							vi.dir = BOTTOM;
							break;
						case TOP:
							--vi.col;
							vi.dir = RIGHT;
							break;
						case BOTTOM:
							++vi.col;
							vi.dir = LEFT;
							break;
						}
						break;
					}

					if (vi.col == col)
						vi.col = 0;
					if (vi.col == -1)
						vi.col = col - 1;
					if (vi.row == row)
						vi.row = 0;
					if (vi.row == -1)
						vi.row = row - 1;

					if (vi.row == temp.row && vi.col == temp.col && vi.dir == temp.dir)
					{
						answer.push_back(cnt);
						break;
					}
					else if (v[vi.row][vi.col].visited[vi.dir])
						break;
					else
						q.push(vi);
				}
			}

	sort(answer.begin(), answer.end());

	return answer;
}

int main()
{
	solution({ "SL","LR" });
	//solution({ "S" });
	//solution({ "R","R" });
	//solution({ "S", "S" });
}
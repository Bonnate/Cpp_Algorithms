#include <string>
#include <vector>

using namespace std;

int sDx[4]{ -1, 1, 0, 0 };
int sDy[4]{ 0, 0, -1, 1 };

int nsDx[4]{ -1, 1, 1, -1 };
int nsDy[4]{ -1, -1, 1, 1 };

int nsDsx[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int nsDsy[4][2]{ {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

bool success(vector<string> s)
{
	for (int y = 0; y < 5; ++y)
		for (int x = 0; x < 5; ++x)
		{
			// 해당 위치에 사람이 있지 않으면 검사하지 않음
			if (s[y][x] != 'P')
				continue;

			for (int i = 0; i < 4; ++i)
			{
				int yy = y + sDy[i];
				int xx = x + sDx[i];

				if (yy == -1 || yy == 5 || xx == -1 || xx == 5)
					continue;

				// 상하좌우 방향에 사람이 있다면 거리두기 규칙 X
				if (s[yy][xx] == 'P')
					return false;

				// 상하좌우 방향에 빈 테이블일경우
				if (s[yy][xx] == 'O')
				{
					// 그 다음 칸에 사람이 있는지 검사
					int yyy = yy + sDy[i];
					int xxx = xx + sDx[i];

					if (yyy == -1 || yyy == 5 || xxx == -1 || xxx == 5)
						continue;

					if (s[yyy][xxx] == 'P')
						return false;
				}
			}
			for (int i = 0; i < 4; ++i)
			{
				int yy = y + nsDy[i];
				int xx = x + nsDx[i];

				if (yy == -1 || yy == 5 || xx == -1 || xx == 5)
					continue;

				// 대각선 위치에 사람이 있다면?
				if (s[yy][xx] == 'P') // 대각선 위치를 가리는 두 방향에 하나라도 파티션이 없다면 거리두기 규칙 X
					if (s[y + nsDsy[i][0]][x + nsDsx[i][0]] != 'X' || s[y + nsDsy[i][1]][x + nsDsx[i][1]] != 'X')
						return false;
			}
		}

	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (vector<string> v : places)
		answer.push_back(success(v) ? 1 : 0);

	printf("%d", answer[0]);
	return answer;
}

int main()
{
	solution({
		//{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
		//{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		//{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
		//{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		//{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"},
		{	"OOPOP",
			"OOOOO",
			"OOOOO",
			"OOOOO",
			"OOOOO"} });
}
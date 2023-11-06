#include <string>
#include <vector>
#include <queue>

using namespace std;

int sel[8];

void DFS(int l, int s)
{
	if (l == 2)
	{
		for (int i = 0; i < 2; ++i)
		{
			printf("%d ", sel[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = s; i < 4; ++i)
		{
			sel[l] = i;
			DFS(l + 1, i + 1);
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	DFS(0, 0);

	int answer = 0;
	return answer;
}

int main()
{
	solution(80, { {80, 20}, { 50,40 }, {30,10} });
}
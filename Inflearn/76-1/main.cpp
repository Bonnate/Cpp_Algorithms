#include <iostream>
#include <vector>
using namespace std;

static int N, R;
static bool arr[21];

static int cnt = 0;

void DFS(int level, bool isInclude)
{
	arr[level] = true;

	if (level == N)
	{
		// 뽑은 원소 개수가 맞는지 검사
		int sum = 0;
		for (int i = 0; i < N; ++i)
			if (arr[i])
				++sum;

		if (sum == R)
			++cnt;
	}
	else
	{
		DFS(level + 1, true);
		arr[level] = false;
		DFS(level + 1, false);
		arr[level] = false;
	}
}

int main()
{
	scanf_s("%d %d", &N, &R);

	DFS(0, true);

	printf("%d", cnt);
}

/*
	5 3
	1 2 3
	1 2 4
	1 2 5
	1 3 4
	1 3 5
	1 4 5
	2 3 4
	2 3 5
	2 4 5
	3 4 5
*/
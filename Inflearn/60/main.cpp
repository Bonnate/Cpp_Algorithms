#include <iostream>
#include <set>
using namespace std;

static int N;
static bool* arr;
static int* numbers;
static bool isOver;

void recur(bool isInclude, int level = 0)
{
	if (isOver)
		return;

	arr[level] = isInclude;

	if (level == N - 1)
	{
		int sum = 0;

		for (int i = 0; i < N; ++i)
			sum += arr[i] ? numbers[i] : -numbers[i];

		if (sum == 0)
			isOver = true;
	}
	else
	{
		recur(true, level + 1);
		recur(false, level + 1);
	}
}

int main()
{
	scanf_s("%d", &N);

	arr = new bool[N];
	numbers = new int[N];

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &numbers[i]);

	recur(true);
	recur(false);

	if (isOver)
		printf("YES");
	else
		printf("NO");
}
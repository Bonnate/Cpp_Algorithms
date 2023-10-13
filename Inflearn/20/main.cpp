#include <iostream>

void CheckGame(int a, int b);

int main()
{
	int arr[2][101];

	int N, A, B;
	scanf_s("%d", &N);

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < N; ++j)
			scanf_s("%d", &arr[i][j]);

	for (int i = 0; i < N; ++i)
		CheckGame(arr[0][i], arr[1][i]);
}

void CheckGame(int a, int b)
{
	// 1: 가위
	// 2: 바위
	// 3: 보

	// 비기는 조건
	if (a == b)
	{
		printf("D\n");
		return;
	}

	// 승부가 나는 조건
	switch (a) // A가 낸 것
	{
	case 1: // 가위
		printf("%s\n", b == 3 ? "A" : "B");
		break;
	case 2: // 바위
		printf("%s\n", b == 1 ? "A" : "B");
		break;
	case 3: // 보
		printf("%s\n", b == 2 ? "A" : "B");
		break;
	}
}
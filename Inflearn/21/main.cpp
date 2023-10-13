#include <iostream>

int main()
{
	enum DRAW_WIN_CODE
	{
		DRAW,
		A_WIN,
		B_WIN,
	};

	int arr[2][10];

	int a = 0, b = 0;

	DRAW_WIN_CODE code = DRAW;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 10; ++j)
			scanf_s("%d", &arr[i][j]);

	// 승점 계산
	for (int i = 0; i < 10; ++i)
	{
		if (arr[0][i] == arr[1][i])
			++a, ++b;
		else if (arr[0][i] > arr[1][i])
		{
			code = A_WIN;
			a += 3;
		}
		else
		{
			code = B_WIN;
			b += 3;
		}
	}

	printf("%d %d\n", a, b);

	// 점수가 같은경우?
	if (a == b)
	{
		switch (code)
		{
		case DRAW:
			printf("D");
			break;
		case A_WIN:
			printf("A");
			break;
		case B_WIN:
			printf("B");
			break;
		}
	}
	else
		printf("%c", a > b ? 'A' : 'B');
}
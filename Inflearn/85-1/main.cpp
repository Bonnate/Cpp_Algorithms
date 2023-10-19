#include <iostream>

int N, min = INT_MAX, max = INT_MIN;

int numbers[11];

// 연산자 경우의 수 (1~9)
bool ch[10];
int res[10];
int operators[10];

int calc(int a, int b, int operatorId)
{
	switch (operatorId)
	{
	case 1:
		return a + b;
	case 2:
		return a - b;
	case 3:
		return a * b;
	case 4:
		return a / b;
	}
}

void DFS(int level)
{
	// 사용 개수가 R에 도달했다면?
	if (level == N - 1)
	{
		// 최초 1회 계산
		int result = calc(numbers[1], numbers[2], operators[res[1]]);

		// 다음부터는 누적된 값으로 계산
		for (int i = 2; i < N; ++i)
			result = calc(result, numbers[i + 1], operators[res[i]]);

		if (max < result)
			max = result;
		if (min > result)
			min = result;
	}
	else
	{
		for (int i = 1; i <= N - 1; ++i)
		{
			if (!ch[i])
			{
				// 출력 결과는 res[level + 1]에 담기
				res[level + 1] = i;

				// ch[i]번째의 값을 현재 사용중
				ch[i] = true;

				// 개수는 1씩 증가
				DFS(level + 1);

				// ch[i]번째의 값을 현재 사용 해제
				ch[i] = false;
			}
		}
	}
}

int main()
{
	scanf_s("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		scanf_s("%d", &numbers[i]);
	}

	int plus, minus, multiply, divide;
	scanf_s("%d %d %d %d", &plus, &minus, &multiply, &divide);

	int idx = 0;
	for (int i = 0; i < plus; ++i)
		operators[++idx] = 1;

	for (int i = 0; i < minus; ++i)
		operators[++idx] = 2;

	for (int i = 0; i < multiply; ++i)
		operators[++idx] = 3;

	for (int i = 0; i < divide; ++i)
		operators[++idx] = 4;

	// 0번 인덱스로 시작
	DFS(0);

	printf("%d\n%d", max, min);
}
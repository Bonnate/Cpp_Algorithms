#include <iostream>

int main()
{
	int N;
	scanf_s("%d", &N);

	int curIncrementCnt = 1;
	int maxIncrementCnt = INT_MIN;

	int prevInput, curInput;

	scanf_s("%d", &prevInput);
	for (int i = 1; i < N; ++i)
	{
		scanf_s("%d", &curInput);

		if (curInput >= prevInput)
			++curIncrementCnt;
		else
			curIncrementCnt = 1;

		if (curIncrementCnt > maxIncrementCnt)
			maxIncrementCnt = curIncrementCnt;

		prevInput = curInput;
	}

	printf("%d", maxIncrementCnt);
}
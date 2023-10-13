#include <iostream>

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	int maxSec = -1;
	int curSec = 0;
	int input;

	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &input);

		if (input > M)
		{
			++curSec;

			if (curSec > maxSec)
				maxSec = curSec;
		}
		else
			curSec = 0;
	}

	printf("%d", maxSec);
}
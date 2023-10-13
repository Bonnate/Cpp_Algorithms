#include <iostream>

int main()
{
	int N;
	scanf_s("%d", &N);

	int cardNum, stdAns;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d %d", &cardNum, &stdAns);

		// 가우스의 합 공식 n(n+1) / 2
		int ans = (cardNum * (cardNum + 1)) / 2;

		printf("%s\n", ans == stdAns ? "YES" : "NO");
	}
}
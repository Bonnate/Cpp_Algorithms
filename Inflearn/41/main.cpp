#include <iostream>

using namespace std;
int main()
{
	int N, totalCnt = 0;
	scanf_s("%d", &N);

	// i는 2, 두자리의 연속 부터 시작
	// i는 i자리의 개수로 가능한가? 를 검사
	// 예를들어 i가 2면, 두자리의 합으로 가능한지 검사
	for (int i = 2; ; ++i)
	{
		// N에서 뺀 나머지 수
		// i가 2라면, N - 1 - 2를 통해 12가 나머지
		int remain = N - (i * (i + 1) / 2);

		if (remain < 0)
			break;

		// remain이 i로 나누어지는지?
		// 나누어진다면, i자리의 수로 표현이 가능해짐
		if (remain % i != 0)
			continue;

		int sum = 0;
		int quotient = remain / i; // remain을 i로 나눈 몫
		++totalCnt;

		// quotient과 j를 더한 값들로 표현
		// 예를들어 i가 2인 상태에서 remain이 6이라면
		// 7 + 8 = 15로 표현 가능
		for (int j = 1; j < i; ++j)
		{
			printf("%d + ", quotient + j);
			sum += (quotient + j);
		}

		printf("%d = %d\n", quotient + i, sum + quotient + i);
	}

	printf("%d", totalCnt);
}
#include <iostream>

int main()
{
	bool isJumper[101]{ false, };

	int N;
	scanf_s("%d", &N);

	int prev = 0, current = 0;
	scanf_s("%d", &prev);
	for (int i = 1; i < N; ++i)
	{
		scanf_s("%d", &current);

		// 차이 구하기
		int diff = std::abs(current - prev);

		// 차이가 100을 넘는 경우는 불가능
		if (diff > 100)
		{
			printf("NO");
			return 0;
		}

		// diff에 해당하는 차이 사용
		isJumper[diff] = true;

		// prev 값 저장
		prev = current;
	}

	for (int i = 1; i < N; ++i)
		if (!isJumper[i])
		{
			printf("NO");
			return 0;
		}
	printf("YES");
}
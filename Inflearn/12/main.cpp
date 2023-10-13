#include <iostream>
#include <string>

int main()
{
	int N;
	scanf_s("%d", &N);

	int answer = 0;
	int digit = 10;

	int digitCount = std::to_string(N).length();

	// 마지막 자리수 전 까지는 규칙대로 더하기
	for (int i = 1; i < digitCount; ++i)
		answer += 9 * std::pow(10, i - 1) * i;

	// 마지막 자리수에서 남은 개수를 구하기
	int left = N - (int)std::pow(10, digitCount - 1) + 1;
	answer += digitCount * left;

	printf("%d", answer);
}
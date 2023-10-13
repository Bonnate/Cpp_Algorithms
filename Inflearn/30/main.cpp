#include <iostream>
#include <string>

using namespace std;
int main()
{
	int N;
	int cnt = 0;
	scanf_s("%d", &N);

	// 입력값을 문자열로
	string str = to_string(N);

	// 문자열의 개수만큼 반복
	for (int i = str.length() - 1; i >= 0; --i)
	{
		int digit = pow(10, str.length() - 1 - i); // 현재 center에 해당하는 자리수

		int left = (i == 0) ? 0 : N / digit / 10; // center 기준 왼쪽
		int center = str[i] - '0'; // 현재 선택한 자리수에 해당하는 값
		int right = (i == str.length() - 1) ? 0 : N % digit; // center 기준 오른쪽 값

		if (center > 3) // center가 3보다 크다면?
		{
			cnt += (left + 1) * digit; // 3을 출력하는 개수는 left 개수 + 1 (자신을 포함)
		}
		else if (center < 3) // center가 3보다 작다면?
		{
			cnt += left * digit; // 3을 출력하는 개수는 left 개수 (자신을 제외)
		}
		else // center가 3이라면?
		{
			cnt += left * digit + right + 1; // 자신을 모두 포함하지 않고, right 개수 + 1만큼 포함
		}
	}

	printf("%d", cnt);
}
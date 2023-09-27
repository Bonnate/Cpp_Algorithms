#include <iostream>

using namespace std;

int main()
{
	int N;
	int age; // 나이 입력 임시 변수

	int max = 2; // 초기 max는 최솟값
	int min = 100; // 초기 min은 최댓값

	scanf_s("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &age);

		if (age > max)
			max = age;
		else if (age < min)
			min = age;
	}

	printf("%d", max - min);
}
#include <iostream>

using namespace std;

int main()
{
	int A, B; // 입력 A, B
	int sum = 0; // 합

	cin >> A >> B; // 입력

	for (int i = A; i < B; ++i)
	{
		printf("%d + ", i);
		sum += i;
	}

	printf("%d = %d", B, sum += B);
}
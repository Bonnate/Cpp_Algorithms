#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	// 배수의 개수
	int cnt = N / M;

	// 최소값
	int min = M;

	// 최대값 
	int max = N - N % M;

	// 결과 (개수가 홀수인경우 중간 값 더해주기)
	int sum = (min + max) * (cnt / 2) + (cnt % 2 == 1 ? (min + max) / 2 : 0);

	// 결과 출력
	cout << sum;
}
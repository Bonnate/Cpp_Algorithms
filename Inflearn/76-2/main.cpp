#include <iostream>

/*
	nCr 은 (n-1 C r-1) + (n-1 C r)로 나뉠 수 있다.

	n==r이 되거나, r이 0이 되면, 경우의 수는 1로 리턴할 수 있다.
	예를들어 5C5와 5C0은 1이다.
*/

// 메모이제이션 (계산된 값을 기억해두기)
int dy[21][21];

int DFS(int N, int R)
{
	// 이미 dy에 값이 있다면 바로 리턴하기
	if (dy[N][R] > 0) return dy[N][R];

	else if (N == R || R == 0) return 1;

	// N,R은 N-1,R-1과 N-1,R로 쪼개어 계산
	else return dy[N][R] = DFS(N - 1, R - 1) + DFS(N - 1, R);
}

int main()
{
	int N, R;
	scanf_s("%d %d", &N, &R);

	printf("%d", DFS(N, R));
}
#include <iostream>

int arr[1001];

// 현재 가르키는 n번이 어느 조합에 속해있는지 리턴
int Find(int n)
{
	// 인덱스 번호와 n이 같다면 자기 자신이 루트 노드
	if (arr[n] == n)
		return n;
	else
		// arr[n] != n이라면, n은 어느 조합에 속해있는 상태이기에 루트를 찾으러 재귀 호출
		// arr[n]에 루트 노드의 값을 넣어 점프할 수 있도록 최적화
		return arr[n] = Find(arr[n]);
}

// a가 속한 조합을 b의 조합으로 변경
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		arr[a] = b;
}

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
		arr[i] = i;

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &a, &b);

		// 입력과 동시에 병합
		Union(a, b);
	}

	scanf_s("%d %d", &a, &b);

	// a 와 b의 조합을 확인
	a = Find(a);
	b = Find(b);

	if (a == b)
		printf("YES");
	else
		printf("NO");
}
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[20], op[5], n, maxi = INT_MIN, mini = INT_MAX;

void DFS(int L, int res)
{
	// 모든 수를 사용했다면?
	if (L == n)
	{
		if (res > maxi) maxi = res;
		if (res < mini) mini = res;
	}
	else
	{
		// 각 연산자의 개수를 모두 소모하여 계산을 시도
		if (op[0] > 0)
		{
			op[0]--;
			DFS(L + 1, res + a[L]);
			op[0]++;
		}
		if (op[1] > 0)
		{
			op[1]--;
			DFS(L + 1, res - a[L]);
			op[1]++;
		}
		if (op[2] > 0)
		{
			op[2]--;
			DFS(L + 1, res * a[L]);
			op[2]++;
		}
		if (op[3] > 0)
		{
			op[3]--;
			DFS(L + 1, res / a[L]);
			op[3]++;
		}
	}
}

int main()
{
	int i;
	scanf_s("%d", &n);

	// 수열 입력
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);

	// 연산자 개수
	for (i = 0; i < 4; i++)
		scanf_s("%d", &op[i]);

	DFS(1, a[0]);
	printf("%d\n%d\n", maxi, mini);
}
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[101], tmp[101];
void divide(int lt, int rt) {
	int mid;
	int p1, p2, p3;
	if (lt < rt) {
		mid = (lt + rt) / 2;

		// 왼쪽 노드 분할
		divide(lt, mid);
		// 오른쪽 노드 분할
		divide(mid + 1, rt);

		/* 자식 노드가 모두 분할되거나, 더 이상 자식노드가 없다면 ? */

		// 양측을 검사할 포인터
		p1 = lt; // 좌측 블록 시작
		p2 = mid + 1; // 우측 블록 시작
		p3 = lt; // 차례대로 값을 채울 인덱스 번호

		// p1이 중간을 넘어가거나, p2가 끝에 도달할때까지 반복
		while (p1 <= mid && p2 <= rt)
		{
			// p1이 p2보다 작다면? (왼쪽 블록이 오른쪽 블록보다 작음)
			if (a[p1] < a[p2])
				tmp[p3++] = a[p1++]; // p1번째의 값을 tmp[p3]에 넣음
			else
				tmp[p3++] = a[p2++]; // p2번째의 값을 tmp[p3]에 넣음
		}

		// p1, p2 중 사용하지 않은 나머지를 소진하여 채우기
		while (p1 <= mid)
			tmp[p3++] = a[p1++]; // 모두 소진
		while (p2 <= rt)
			tmp[p3++] = a[p2++]; // 모두 소진

		// 실제 값을 변경
		for (int i = lt; i <= rt; i++) {
			a[i] = tmp[i];
		}
	}
}

int main() {
	int n, i;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	divide(1, n);
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
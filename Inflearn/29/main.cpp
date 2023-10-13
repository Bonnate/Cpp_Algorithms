#include<stdio.h>
int res;
int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = i; j > 0; j = j / 10) {
			if (j % 10 == 3) res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
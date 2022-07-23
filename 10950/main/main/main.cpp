#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		int a, b;
		scanf_s("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}
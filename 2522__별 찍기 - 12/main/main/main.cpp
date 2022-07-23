#include <iostream>
using namespace std;

int main()
{
	int n;

	scanf_s("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			printf(" ");
		}
		for (int k = 0; k < i + 1; ++k)
		{
			printf("*");
		}

		printf("\n");
	}

	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < i + 1; ++k)
		{
			printf(" ");
		}
		for (int j = i + 1; j < n; ++j)
		{
			printf("*");
		}


		printf("\n");
	}
}
#include <iostream>

int main()
{
	int arr[10] = { 0, };

	char numStr[101];
	scanf_s("%s", numStr, sizeof(numStr));

	for (int i = 0; i < numStr[i] != '\0'; ++i)
		++arr[numStr[i] - '0'];

	int max = -1;
	int maxCnt = -1;
	for (int i = 0; i < 10; ++i)
	{
		if (maxCnt <= arr[i])
		{
			maxCnt = arr[i];
			max = i;
		}
	}

	printf("%d", max);
}
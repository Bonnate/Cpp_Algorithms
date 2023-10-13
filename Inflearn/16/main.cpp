#include <iostream>

void checkStr(char* str, bool isFirstStr);

static int upperChar[26]{ 0, };
static int lowerChar[26]{ 0, };

int main()
{
	char str1[101], str2[101];

	scanf_s("%s", str1, sizeof(str1));
	scanf_s("%s", str2, sizeof(str2));

	checkStr(str1, true);
	checkStr(str2, false);

	for (int i = 0; i < 26; ++i)
		if (upperChar[i] != 0 || lowerChar[i] != 0)
		{
			printf("NO");
			return 0;
		}

	printf("YES");
}

void checkStr(char* str, bool isFirstStr)
{
	for (int i = 0; str[i] != '\0'; ++i)
		if (str[i] >= 'a')
			isFirstStr ? ++upperChar[str[i] - 'a'] : --upperChar[str[i] - 'a'];
		else
			isFirstStr ? ++upperChar[str[i] - 'a'] : --upperChar[str[i] - 'a'];
}
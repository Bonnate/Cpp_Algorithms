#include <iostream>

int sel;
int used[10];
int ch[10];
char arr[10]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

/// <summary>
/// 순서를 무시하고 가능한 모든 경우의 수를 조합
/// </summary>
/// <param name="s"></param>
void DFS_ALL_Combinations(int s)
{
	if (s == sel)
	{
		for (int i = 0; i < sel; ++i)
			printf("%c ", arr[ch[i]]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < sel; ++i)
			if (!used[i])
			{
				used[i] = true;
				ch[s] = i;
				DFS_ALL_Combinations(s + 1);
				used[i] = false;
			}
	}
}

/// <summary>
/// 순서를 중요시하여 중복이 제거된 조합
/// </summary>
/// <param name="l"></param>
/// <param name="s"></param>
void DFS_DISTINCT_Combinations(int l, int s)
{
	if (s == sel)
	{
		for (int i = 0; i < sel; ++i)
			printf("%c ", arr[ch[i]]);
		printf("\n");
	}
	else
	{
		// i는 현재 선택 개수부터 시작하여 선택할 마지막 값까지 반복
		for (int i = l; i < 10; ++i)
		{
			ch[s] = i; // s번째 선택한 값은 i번
			DFS_DISTINCT_Combinations(i + 1, s + 1); // 다음 선택으로 이동
		}
	}
}

int main()
{
	sel = 3;
	//DFS_ALL_Combinations(0);
	//DFS_DISTINCT_Combinations(0, 0);
}
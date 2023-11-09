#include <iostream>
#include <vector>
using namespace std;

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
		// 0부터 sel까지 반복
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
/// 중복이 없는 조합을 뽑기
/// </summary>
/// <param name="s">시작 값 start</param>
/// <param name="p">선택 원소 위치 place</param>
void DFS_Combinations(int s, int p)
{
	// position이 sel(뽑아야 할 총 개수)라면?
	if (p == sel)
	{
		for (int i = 0; i < sel; ++i)
			printf("%c ", arr[ch[i]]);
		printf("\n");
	}
	else
	{
		// i는 현재 선택 개수부터 시작하여 선택할 마지막 값까지 반복
		for (int i = s; i < 4; ++i)
		{
			ch[p] = i; // s번째 선택한 값은 i번

			// i + 1를 start로, p + 1을 position으로하여 다음 재귀 호출
			DFS_Combinations(i + 1, p + 1);
		}
	}
}

vector<int> combination; // 현재까지 뽑은 조합을 저장하는 배열
void generateCombination(int start, int r, vector<int>& arr)
{
	// 기저 조건: r개의 원소를 선택한 경우
	if (r == 0)
	{
		for (int n : combination)
			printf("%d ", n);
		printf("\n");
		return;
	}

	// 재귀 호출
	for (int i = start; i < arr.size(); ++i)
	{
		combination.push_back(arr[i]); // 값을 뒤에 삽입
		generateCombination(i + 1, r - 1, arr); // 다음값(i+1)부터 시작하고, r(선택해야할 개수)은 1빼기
		combination.pop_back(); // 뒤에서 값 제거
	}
}

int main()
{
	sel = 4;

	DFS_ALL_Combinations(0); // sel개의 모든 조합
}
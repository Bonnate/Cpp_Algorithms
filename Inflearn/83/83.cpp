#include <iostream>

// S E N D M O R Y
// 각 인덱스 번호에는 위에 해당하는 문자로 간주되어 계산
int arr[8];

// 0부터 9까지를 사용했는지 체크
bool ch[10];

int SEND()
{
	// arr의 각 인덱스 번호에 해당하는대로 네자리 숫자로 출력
	return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3] * 1;
}

int MORE()
{
	return arr[4] * 1000 + arr[5] * 100 + arr[6] * 10 + arr[1] * 1;
}

int MONEY()
{
	return arr[4] * 10000 + arr[5] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[7] * 1;
}

void DFS(int cnt)
{
	if (cnt == 8)
	{
		if (SEND() + MORE() == MONEY())
		{
			// 만약 S, M의 자리가 0이라면 리턴
			if (arr[0] == 0 || arr[4] == 0)
				return;

			// 답 출력
			printf("  %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
			printf("+ %d %d %d %d\n", arr[4], arr[5], arr[6], arr[1]);
			printf("---------\n");
			printf("%d %d %d %d %d\n", arr[4], arr[5], arr[2], arr[1], arr[7]);

			exit(0);
		}
	}
	else
	{
		// 0부터 9까지 가능한 숫자 조합을 반복
		for (int i = 0; i < 10; ++i)
		{
			// 숫자 i를 사용하지 않았다면?
			if (!ch[i])
			{
				// arr[cnt]는 i
				arr[cnt] = i;

				// 숫자 i 사용 완료
				ch[i] = true;

				// 재귀 호출
				DFS(cnt + 1);

				// 숫자 i 사용 종료
				ch[i] = false;
			}
		}
	}
}

int main()
{
	DFS(0);
}
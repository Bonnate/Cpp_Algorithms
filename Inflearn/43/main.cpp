#include <iostream>
#include <vector>

using namespace std;

int getCnt(vector<int> arr, int N, int size)
{
	int sum = 0;
	int cnt = 1; // 시작 DVD의 개수는 1

	for (int i = 0; i < N; ++i)
	{
		if (sum + arr[i] > size) // DVD의 용량을 초과한경우?
		{
			++cnt; // DVD를 일단 채웠기때문에 1 증가
			sum = arr[i]; // 초과한 다음 분은 sum에 넣기
		}
		else // DVD의 용량을 아직 못채운경우
		{
			sum += arr[i]; // 용량을 더하여 채우기
		}
	}

	return cnt;
}

int main()
{
	int N, M;
	int lt = 0, rt = 0, mid, res, max = INT_MIN;

	scanf_s("%d %d", &N, &M);
	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &arr[i]);
		rt += arr[i];
		max = max > arr[i] ? max : arr[i];
	}

	// lt의 크기가 rt의 크기보다 커질때까지 반복
	while (lt <= rt)
	{
		// DVD의 크기는 (lt + rt) / 2
		mid = (lt + rt) / 2;

		// mid(현재 DVD 사이즈)로 나누었을때, DVD의 개수
		int cnt = getCnt(arr, N, mid);

		// DVD의 크기는 max 이상이어야하며, DVD의 개수가 M보다 작거나 같다면?
		if (mid >= max && cnt <= M)
		{
			res = mid; // res는 가능한 정답
			rt = mid - 1; // rt를 줄여 최적의 답 찾기를 한번 더 시도
		}
		// DVD의 크기(mid)가 max보다 작거나, cnt가 M(나눔 수)보다 크다면?
		else
		{
			lt = mid + 1; // lt를 올려 DVD의 크기를 늘려 cnt를 M에 맞추도록 시도
		}
	}

	printf("%d", res);
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	/*
	int idx = N / 2;
	while (true)
	{
		// 현재 idx의 원소값이 찾고자 하는 값보다 크면?
		if (arr[idx] > M)
			idx = idx / 2;
		// 현재 idx의 원소값이 찾고자 하는 값보다 작으면?
		else if (arr[idx] < M)
			idx = (idx + N) / 2;
		else
		{
			printf("%d", idx + 1);
			break;
		}
	}
	*/

	// lt, mid, rt를 명시하여 구현

	int lt = 0, rt = N - 1, mid;

	while (true)
	{
		mid = (lt + rt) / 2;

		if (arr[mid] == M) // 값을 찾았다면?
		{
			printf("%d", mid + 1);
			break;
		}
		else if (arr[mid] > M) // 현재 값이 찾고자 하는 값보다 크면? -> mid를 감소
		{
			rt = mid - 1;
		}
		else // 현재 값이 찾고자 하는 값보다 작으면? -> mid를 증가
		{
			lt = mid + 1;
		}
	}
}
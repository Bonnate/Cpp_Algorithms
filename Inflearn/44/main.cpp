#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool trySetHorse(vector<int> arr, int c, int gap)
{
	int i = 0;
	int n = arr.size(); // 마구간의 개수

	// 첫번째 말은 0번에 배치하도록
	--c;

	for (; i < n - 1; ++i)
	{
		for (int j = i; j < n - 1; ++j)
		{
			if (arr[j + 1] - arr[i] >= gap)
			{
				i = j + 1;
				--c;
			}

			if (c == 0)
				return true;
		}
	}

	return false;
}

int main()
{
	int N, C;
	scanf_s("%d %d", &N, &C);

	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	int lt = 1, rt = arr[N - 1], mid;
	int res = 0;

	while (lt <= rt)
	{
		mid = (lt + rt) / 2;

		bool isSuccess = trySetHorse(arr, C, mid);

		if (isSuccess) // 말 배치에 성공하였다면?
		{
			res = mid;
			// lt를 올려 최대 거리를 늘리기
			lt = mid + 1;
		}
		else // 말 배치에 실패하였다면?
		{
			// rt를 줄여 최대 거리를 줄이기
			rt = mid - 1;
		}
	}

	printf("%d", res);
}
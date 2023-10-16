#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N, K;
	scanf_s("%d %d", &N, &K);

	vector<int> arr;
	for (int i = 0; i < N; ++i)
		arr.push_back(i + 1);

	int idx = 0;
	int check = 0;
	int left = N;

	while (true)
	{
		if (arr[idx] != -1)
		{
			++check;
			if (check == K)
			{
				arr[idx] = -1;
				--left;
				check = 0;

				if (left == 1)
				{
					for (int i = 0; i < N; ++i)
						if (arr[i] != -1)
						{
							printf("%d", arr[i]);
							return 0;
						}
				}
			}
		}

		++idx;
		if (idx == N)
			idx = 0;
	}
}
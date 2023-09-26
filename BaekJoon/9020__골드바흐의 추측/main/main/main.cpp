#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;
int main()
{
	bool* flags;
	int T, n, max = -1;;
	vector<int> testCase;

	scanf_s("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		scanf_s("%d", &n);

		max = n > max ? n : max;

		testCase.push_back(n);
	}

	flags = new bool[max + 1]();

	for (int i = 2; i <= sqrt(max + 1); ++i)
	{
		if (!flags[i])
		{
			for (int j = i * 2; j <= max + 1; j += i)
			{
				flags[j] = true;
			}
		}
	}

	for (int i = 0; i < testCase.size(); ++i)
	{
		for (int j = testCase[i] * 0.5f; j >= 2; --j)
		{
			if (!flags[j] && !flags[testCase[i] - j])
			{
				printf("%d %d\n", j, testCase[i] - j);
				break;
			}
		}
	}
}
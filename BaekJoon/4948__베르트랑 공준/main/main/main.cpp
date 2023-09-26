#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;
int main()
{
	vector<int> perCase;
	int input, max = -1;
	bool* flag;


	while (1)
	{
		scanf_s("%d", &input);

		if (input)
		{
			max = input > max ? input : max;
			perCase.push_back(input);
		}
		else
		{
			flag = new bool[max * 2 + 1]();
			flag[1] = true;
			
			for (int i = 2; i <= sqrt(max * 2 + 1); ++i)
			{
				if (!flag[i])
				{
					for (int j = i * 2; j <= max * 2 + 1; j += i)
					{
						flag[j] = true;
					}
				}
			}

			int ans = 0;

			for (int i = 0; i < perCase.size(); ++i)
			{
				ans = 0;

				for (int j = perCase[i] + 1; j <= perCase[i] * 2; ++j)
				{
					if (!flag[j])
					{
						++ans;
					}

				}

				printf("%d\n", ans);
			}

			return 0;
		}
	}

	
}
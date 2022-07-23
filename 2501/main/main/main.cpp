#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n, k;
	vector<int> divisor;

	scanf("%d %d", &n, &k);

	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			int temp = n / i;

			if (temp == i)
			{
				divisor.push_back(i);
				continue;
			}

			divisor.push_back(i);
			divisor.push_back(n / i);
		}
	}

	if (divisor.size() < k)
	{
		cout << 0;
	}
	else
	{
		sort(divisor.begin(), divisor.end());
		cout << divisor[k - 1];
	}
}
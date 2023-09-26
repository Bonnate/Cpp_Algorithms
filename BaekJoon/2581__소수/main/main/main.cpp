#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int min, max, s = 0;
	vector<int> p;

	cin >> min >> max;

	for (int i = min; i <= max; ++i)
	{
		if (i < 2) continue;

		bool isP = true;

		for (int j = 2; j * j <= i; ++j)
		{
			if (i % j == 0)
			{
				isP = false;
				break;
			}
		}

		if (isP)
		{
			p.push_back(i);
		}
	}

	for (int i = 0; i < p.size(); ++i)
	{
		s += p[i];
	}

	if (p.size())
	{
		cout << s << endl << p[0];
	}
	else
	{
		cout << -1;
	}

}
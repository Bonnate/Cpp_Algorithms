#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string a, b;
	vector<int> ans;
	cin >> a >> b;

	if (a.length() > b.length())
	{
		while (a.length() != b.length())
		{
			b.insert(0, "0");
		}
	}
	else
	{
		while (a.length() != b.length())
		{
			a.insert(0, "0");
		}
	}

	bool isRound = 0;
	int sum;
	for (int i = a.length() - 1; i >= 0; --i)
	{
		sum = (a[i] - '0' + b[i] - '0');
		if (isRound)
		{
			++sum;
		}
		
		if (sum >= 10)
		{
			isRound = 1;
		}
		else
		{
			isRound = 0;
		}

		ans.push_back(sum % 10);
	}

	if(isRound) ans.push_back(1);

	for (int i = ans.size() - 1; i >= 0; --i)
	{
		cout << ans[i];
	}
}
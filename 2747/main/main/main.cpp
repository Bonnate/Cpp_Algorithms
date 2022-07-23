#include <iostream>
using namespace std;

int main()
{
	int n, temp, prev = 0, cur = 1;

	cin >> n;

	if (n < 1)
	{
		cout << n;
		return 0;
	}

	while (--n)
	{
		temp = prev;
		prev = cur;
		cur = prev + temp;
	}

	cout << cur;
}
#include <iostream>
using namespace std;

int main()
{
	int n, input, ans;

	cin >> n;

	ans = -n;

	while (n--)
	{
		cin >> input;

		ans += input;
	}

	++ans;

	cout << ans;
}
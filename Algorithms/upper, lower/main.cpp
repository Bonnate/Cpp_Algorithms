#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s = "AbCdEfGhI";

	transform(s.begin(), s.end(), s.begin(), [](char c)
		{
			return tolower(c);
		});

	cout << s << endl;
}
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int from = 0, to = 0, res;
	string temp;

	cin >> temp;
	from = ((temp[0] - '0') * 10 + (temp[1]) - '0') * 60 * 60 + ((temp[3] - '0') * 10 + (temp[4]) - '0') * 60 + ((temp[6] - '0') * 10 + (temp[7]) - '0');

	cin >> temp;
	to = ((temp[0] - '0') * 10 + (temp[1]) - '0') * 60 * 60 + ((temp[3] - '0') * 10 + (temp[4]) - '0') * 60 + ((temp[6] - '0') * 10 + (temp[7]) - '0');

	if (from > to)
	{
		to += 24 * 60 * 60;
	}
	res = (abs)(from - to);

	int hour = res / 3600;
	int min = res % 3600 / 60;
	int sec = res % 60;

	printf("%02d:%02d:%02d", hour, min, sec);
}
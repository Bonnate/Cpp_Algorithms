#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	double val, max = -1.0;
	vector<double> vals;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> val;
		vals.push_back(val);

		max = val > max ? val : max;
	}

	double sum = 0;
	for (vector<double>::iterator iter = vals.begin(); iter != vals.end(); ++iter)
	{
		sum += *iter / max * 100.0;
	}

	cout << sum / n;
}
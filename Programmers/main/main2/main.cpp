#include <string>
#include <vector>

using namespace std;

int main()
{
	long long begin = 1;
	long long end = 5000;

	vector<int> answer(end - begin + 1);

	for (int i = begin; i <= end; ++i)
	{
		for (int j = i * 2; j <= end; j += i)
		{
			answer[j - 1] = i;
		}
	}

	int a;
}
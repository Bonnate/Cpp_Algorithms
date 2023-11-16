#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int max = *max_element(priorities.begin(), priorities.end());
	while (true)
	{
		for (int i = 0; i < priorities.size(); ++i)
		{
			if (priorities[i] == max)
			{
				++answer;

				if (i == location)
					return answer;

				priorities[i] = 0;
				max = *min_element(priorities.begin(), priorities.end());
			}
		}
	}
}

int main()
{
	solution({ 1, 1, 9, 1, 1, 1 }, 0);
}
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size());

	stack<pair<int, int>> s;
	for (int i = 0; i < numbers.size(); ++i)
	{
		while (!s.empty())
		{
			if (numbers[i] > s.top().first)
			{
				answer[s.top().second] = numbers[i];
				s.pop();
			}
			else
				break;
		}

		s.push({ numbers[i], i });
	}

	while (!s.empty())
	{
		answer[s.top().second] = -1;
		s.pop();
	}

	return answer;
}

int main()
{
	solution({ 2, 3, 3, 5 });
	//solution({ 9, 1, 5, 3, 6, 2 });
}
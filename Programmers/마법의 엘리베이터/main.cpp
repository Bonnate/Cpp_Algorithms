#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
	int answer = 0;
	int digit = 1;

	while (true)
	{
		int front = storey % 100 / 10;
		int back = storey % 10;

		if (back != 5)
		{
			if (back > 5)
				storey += 10, answer += (10 - back);
			else
				answer += back;
		}
		else if (front >= 5) // back이 5일때 front가 5보다 크면?
			answer += (10 - back), storey += 10;
		else // back이 5일때 front가 이하라면?
			answer += back;

		storey /= 10;

		if (storey < 10)
		{
			if (storey < 6)
				answer += storey;
			else
				answer += (10 - storey + 1);
			break;
		}
	}

	return answer;
}

int main()
{
	solution(5555);
}
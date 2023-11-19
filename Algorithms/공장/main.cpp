#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> truck, vector<int> w) {
	vector<int> answer;
	map<int, priority_queue<int>> m;

	for (int i = 0; i < truck.size(); ++i)
	{
		printf("%d %d\n", truck[i], i);
		m[truck[i]].push(-i);
	}

	for (int i = 0; i < w.size(); ++i)
	{
		int minIdx = 150001;
		int currentWeight = 0;

		for (pair<int, priority_queue<int>> p : m)
		{
			if (w[i] <= p.first)
			{
				if (minIdx > -p.second.top())
				{
					minIdx = -p.second.top(); // 인덱스 번호
					currentWeight = p.first;

					printf("test: %d %d\n", currentWeight, minIdx);
				}
			}
		}

		printf("%d %d\n", minIdx, currentWeight);

		minIdx; // 현재 무게가 있는 인덱스 번호
		currentWeight; // 인덱스 번호에 해당하는 트럭의 남은 용량

		answer.push_back(minIdx);

		m[-currentWeight].pop();
		m[-(currentWeight - w[i])].push(-minIdx);

		if (m[-currentWeight].empty())
			m.erase(-currentWeight);
	}

	return answer;
}

int main()
{
	solution({ 1, 4, 5, 2, 4 }, { 2, 4, 4, 3, 2 });
}
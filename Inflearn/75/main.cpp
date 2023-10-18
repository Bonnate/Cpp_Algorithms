#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct lecture {
	int day;
	int cost;

	lecture(int cost, int day) : day(day), cost(cost) {}

	// 연산자 오버로딩으로 day를 내림차순 정렬할 수 있도록 설정
	bool operator < (const lecture& ref) const
	{
		return day > ref.day;
	}
};

int main()
{
	int N;
	scanf_s("%d", &N);

	vector<lecture> l;
	priority_queue<int> pQ;

	int day, cost, maxDay = INT_MIN, sum = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d %d", &cost, &day);
		l.push_back(lecture(cost, day));

		if (maxDay < day)
			maxDay = day;
	}

	// day를 기준으로 내림차순 정렬
	// day가 높아야 일을 늦게까지 대기시킬 수 있음
	sort(l.begin(), l.end());

	int j = 0;
	// day가 높은 순서대로 시작
	for (int i = maxDay; i >= 1; --i)
	{
		// 정렬된 l을 0부터 검사
		for (; j < N; ++j)
		{
			// 현재 선택된 day와 같다면 큐에 삽입
			if (l[j].day == i)
				pQ.push(l[j].cost);
			else
				break;
		}

		// 큐에 값이 있다면 pop하여 sum에 더하기
		if (!pQ.empty())
		{
			sum += pQ.top();
			pQ.pop();
		}
	}

	printf("%d", sum);
}
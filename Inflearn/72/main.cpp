#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	scanf_s("%d %d", &N, &K);

	queue<int> q;

	for (int i = 0; i < N; ++i)
		q.push(i + 1);

	while (q.size() > 1)
	{
		for (int i = 0; i < K - 1; ++i)
		{
			int currentId = q.front();
			q.pop();
			q.push(currentId);
		}

		q.pop();
	}

	printf("%d", q.front());
}
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int main()
{
	int N;
	stack<int> stack;
	queue<char> queue;

	scanf_s("%d", &N);
	int* arr = new int[N];
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	int nextTrainId = 1, idx = 0, deadLock = 0;
	while (1)
	{
		if (!stack.empty() && stack.top() == nextTrainId)
		{
			stack.pop();
			++nextTrainId;
			queue.push('O');

			if (stack.empty() && idx == N)
				break;
			else
				continue;
		}

		queue.push('P');
		stack.push(arr[idx++]);

		++deadLock;

		if (deadLock > N)
		{
			printf("impossible");
			return 0;
		}
	}

	while (!queue.empty())
	{
		printf("%c", queue.front());
		queue.pop();
	}
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int a;

	// 내림차순 (기본값)
	//priority_queue<int> pQ;

	// 오름차순 greater<int>를 명시
	priority_queue<int, vector<int>, greater<int>> pQ;

	while (true)
	{
		scanf_s("%d", &a);
		if (a == -1)
			break;

		if (a == 0)
			if (pQ.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", pQ.top());
				pQ.pop();
			}
		else
		{
			pQ.push(a);
		}
	}
}
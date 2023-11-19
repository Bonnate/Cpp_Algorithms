#include <iostream>
#include <queue>
using namespace std;

int main()
{
	vector<vector<int>> v(10, vector<int>(20, 30));

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqASC;
	for (int i = 0; i < 10; ++i)
	{
		pqASC.push({ rand() % 1000, rand() % 1000 });
	}

	for (int i = 0; i < 10; ++i)
	{
		pqASC.push({ 500, rand() % 1000 });
	}

	cout << "오름차순" << endl;
	while (!pqASC.empty())
	{
		printf("%d %d\n", pqASC.top().first, pqASC.top().second);
		pqASC.pop();
	}

	priority_queue <pair<int, int>> pqDESC;
	for (int i = 0; i < 10; ++i)
	{
		pqDESC.push({ rand() % 1000, rand() % 1000 });
	}

	for (int i = 0; i < 10; ++i)
	{
		pqDESC.push({ 500, rand() % 1000 });
	}

	cout << "내림차순" << endl;
	while (!pqDESC.empty())
	{
		printf("%d %d\n", pqDESC.top().first, pqDESC.top().second);
		pqDESC.pop();
	}

	priority_queue <int, vector<int>, greater<int>> pqIntASC;
	for (int i = 0; i < 10; ++i)
	{
		pqIntASC.push({ rand() % 1000 });
	}

	for (int i = 0; i < 10; ++i)
	{
		pqIntASC.push({ 500 });
	}

	cout << "내림차순" << endl;
	while (!pqIntASC.empty())
	{
		printf("%d\n", pqIntASC.top());
		pqIntASC.pop();
	}
}
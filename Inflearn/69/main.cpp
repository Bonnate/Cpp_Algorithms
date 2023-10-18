#include <iostream>
#include <vector>
using namespace std;

int queue[100], front = -1, back = -1;
vector<int> map[10];
int ch[10];

int main()
{
	int f, t; // from, to

	for (int i = 0; i < 6; ++i)
	{
		scanf_s("%d %d", &f, &t);
		map[f - 1].push_back(t - 1);
	}

	for (int i = 0; i < 10; ++i)
		ch[i] = false;

	// 0번째 노드로 시작
	queue[++back] = 0;
	ch[0] = true;

	// front가 back을 역전할때까지 반복
	while (front < back)
	{
		// 현재 노드의 값을 꺼내옴 및 front 증가
		f = queue[++front];
		printf("%d ", f + 1);

		// 현재 노드에서 갈 수 있는 모든 노드를 검사
		for (int i = 0; i < map[f].size(); ++i)
			// 방문하지 않은 노드라면?
			if (ch[map[f][i]] == false)
			{
				// 해당 노드 번호를 큐에 삽입 및 back 증가
				queue[++back] = map[f][i];
				ch[map[f][i]] = true;
			}
	}
}
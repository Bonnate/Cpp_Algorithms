#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
	map<int, int> m;

	for (int n : tangerine)
		++m[n];

	// 우선순위 큐를 이용하여 남은 귤의 개수가 적은것부터 내림차순
	priority_queue<pair<int, int>> q;
	for (pair<int, int> p : m)
		q.push({ -p.second, p.first });

	// left: 제거해야 할 귤의 개수
	int left = tangerine.size() - k;
	for (int i = 0; i < tangerine.size() - k; ++i)
	{
		// 현재 제거할 귤의 개수
		int cnt = -q.top().first;

		// left가 적어 제거하지 못하는경우 리턴
		if (cnt > left)
			break;
		// 제거 가능한경우에는 큐에서 pop
		else
		{
			left -= cnt;
			q.pop();
		}
	}

	return q.size();
}

int main()
{
	//solution(6, { 1, 3, 2, 5, 4, 5, 2, 3 });
	//solution(4, { 1, 3, 2, 5, 4, 5, 2, 3 });
	solution(2, { 1, 1, 1, 1, 2, 2, 2, 3 });
}
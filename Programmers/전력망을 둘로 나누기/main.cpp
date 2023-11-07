#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
	int answer = 101;

	vector<bool> visit(n + 1);
	vector<vector<int>> v = vector<vector<int>>(n + 1, vector<int>());
	queue<int> q;

	for (vector<int> vv : wires)
	{
		v[vv[0]].push_back(vv[1]);
		v[vv[1]].push_back(vv[0]);
	}

	for (int i = 0; i < wires.size(); ++i)
	{
		int value = 0;

		// 방문하지 않은 네트워크 노드에 방문하기
		for (int j = 1; j < visit.size(); ++j)
			if (!visit[j])
			{
				int cnt = 0;

				q.push(j);
				visit[j] = true;

				for (int n : v[j])
					if (!visit[n])
					{
						if ((wires[i][0] == j && wires[i][1] == n) || (wires[i][0] == n && wires[i][1] == j))
							continue;

						visit[n] = true;
						q.push(n);
					}

				while (!q.empty())
				{
					int from = q.front();
					q.pop();
					++cnt;

					for (int n : v[from])
						if (!visit[n])
						{
							if ((wires[i][0] == from && wires[i][1] == n) || (wires[i][0] == n && wires[i][1] == from))
								continue;

							visit[n] = true;
							q.push(n);
						}
				}

				value += value ? -cnt : +cnt;
			}

		for (int j = 1; j <= n; ++j)
			visit[j] = false;

		answer = min(answer, abs(value));
	}

	return answer;
}

int main()
{
	//solution(9, { {1, 3}, { 2,3 }, { 3,4 }, { 4,5 }, { 4,6 }, { 4,7 }, { 7,8 }, { 7,9 } });
	//solution(4, { {1, 2}, { 2,3 }, { 3,4 } });
	solution(7, { {1, 2}, { 2,7 }, { 3,7 }, { 3,4 }, { 4,5 }, { 6,7 } });
}
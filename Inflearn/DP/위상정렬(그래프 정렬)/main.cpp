#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n, m, a, b, score;
	cin >> n >> m;

	// 그래프 간선 정보를 저장
	vector<vector<int> > graph(n + 1, vector<int>(n + 1, 0));
	// 그래프의 차수를 저장
	vector<int> degree(n + 1);
	// 큐
	queue<int> Q;

	// 입력을 받아 그래프 간선 정보를 설정
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a][b] = 1;

		// 입력에 대한 차수를 미리 증가시키기 (선행 작업이 있음)
		degree[b]++;
	}

	// 차수가 0인 모든 간선을 삽입
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		cout << now << " ";

		// 현재 간선에서 다른 간선으로의 입력이 있다면, 해당 간선의 차수를 감소시킴
		// 감소된 간선을 큐에 삽입하여 반복
		for (int i = 1; i <= n; i++)
		{
			if (graph[now][i] == 1)
			{
				degree[i]--;
				if (degree[i] == 0)
					Q.push(i);
			}
		}
	}
	return 0;
}
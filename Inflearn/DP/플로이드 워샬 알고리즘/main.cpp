#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);

	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<int> > dis(n + 1, vector<int>(n + 1, 5000));

	// 자기 자신에 대한 비용은 0
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;

	// 바로 갈 수 있는 노드는 미리 값을 적어두기
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		dis[a][b] = c;
	}

	// 플로이드 와샬
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				// 기존 값 dis[i][j]보다  dis[i][k] + dis[k][j]가 더 적다면?
				// 기존 저장된 값보다, i -> k -> j가 더 비용이 낮으면?
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] == 5000)
			{
				cout << "M ";
			}
			else cout << dis[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
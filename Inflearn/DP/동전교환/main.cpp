#include<iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;

	vector<int> coin(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	cin >> m;

	// 적당히 큰 값으로 초기화 (INT_MAX)를 하면 오버플로우가 나옴
	vector<int> dy(m + 1, 1000);

	dy[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int value = coin[i];

		for (int j = value; j <= m; j++)
		{
			// 거스름돈 동전 개수는 value 전 값에서 + 1
			dy[j] = min(dy[j], dy[j - value] + 1);
		}
	}

	cout << dy[m];
	return 0;
}
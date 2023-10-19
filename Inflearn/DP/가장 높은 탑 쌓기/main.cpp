#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100];

struct brick
{
	int width;
	int height;
	int weight;

	brick() {}
	brick(int width, int height, int weight) : width(width), height(height), weight(weight) {}

	const bool operator < (const brick& ref) const
	{
		return width > ref.width;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);

	int N, width, height, weight, res = INT_MIN;
	cin >> N;

	vector<brick> bricks(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> width >> height >> weight;
		bricks[i] = brick(width, height, weight);
	}

	// 가로 길이를 기준으로 정렬
	sort(bricks.begin(), bricks.end());

	dp[0] = bricks[0].height;

	// 이제부터는 무게를 기준으로만 계산
	for (int i = 1; i < N; ++i)
	{
		int max = bricks[i].height;
		for (int j = i - 1; j >= 0; --j)
		{
			// 아래 벽돌의 무게가 더 무거워야함
			if (bricks[i].weight < bricks[j].weight)
			{
				if (max < dp[j] + bricks[i].height)
					max = dp[j] + bricks[i].height;
			}

			dp[i] = max;
			if (dp[i] > res)
				res = dp[i];
		}
	}

	cout << res;
}
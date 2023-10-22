#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> isPrime;
vector<int> sel(3);
int cnt = 0;

void DFS(vector<int> nums, int level, int select)
{
	if (level == 3) // 3개의 숫자를 선택
	{
		int sum = 0;
		for (int i = 0; i < 3; ++i)
			sum += nums[sel[i]];

		if (isPrime[sum])
			++cnt;
	}
	else
	{
		for (int i = select; i < nums.size(); ++i)
		{
			sel[level] = i;
			DFS(nums, level + 1, i + 1); // select 변수를 i + 1로 업데이트
		}
	}
}

int solution(vector<int> nums) {
	int maxV = INT_MIN;
	for (int i = 0; i < nums.size(); ++i)
		maxV = max(maxV, nums[i]);

	isPrime = vector<bool>(maxV * 1000, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrt(isPrime.size()); ++i)
		for (int j = i * 2; j < isPrime.size(); j += i)
			isPrime[j] = false;

	sel = vector<int>(nums.size());

	DFS(nums, 0, 0);

	return cnt;;
}

int main()
{
	cout << solution({ 1, 2, 7, 6, 4 });
}
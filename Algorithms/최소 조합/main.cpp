#include <iostream>
#include <vector>

int countCombinations(const std::vector<int>& arr, int target) {
	std::vector<int> dp(target + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < arr.size(); ++i) {
		for (int j = arr[i]; j <= target; ++j) {
			dp[j] += dp[j - arr[i]];
		}
	}

	return dp[target];
}

int main() {
	std::vector<int> nums = { 2, 2, 2, 2, 2 };
	int target = 5;

	int result = countCombinations(nums, target);
	std::cout << "최소 조합의 개수: " << result << std::endl;

	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::vector<int> arr = { 1, 2, 3 }; // 순열을 만들 배열

	// 순열 생성
	do {
		for (int i = 0; i < arr.size(); ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	} while (std::next_permutation(arr.begin(), arr.end()));

	return 0;
}
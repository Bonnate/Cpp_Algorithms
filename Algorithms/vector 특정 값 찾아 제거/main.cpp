#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<string> v = { "apple", "orange", "banana", "orange", "grape" };

	string _s = "orange";

	// 벡터에서 특정 값 찾기
	auto it = find(v.begin(), v.end(), _s);

	if (it != v.end()) {
		// 값을 찾았으면 제거
		v.erase(it);
	}

	// 제거 후 벡터 출력
	for (const auto& element : v) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
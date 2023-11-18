#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int> v = { 1, 2, 3, 3, 3, 3, 5, 6, 7, 8, 9 };

	bool found = binary_search(v.begin(), v.end(), 3);

	cout << "기존 벡터 값: ";
	for (int n : v)
		cout << n << " ";
	cout << endl;

	if (found) {
		cout << "3이 존재함" << endl;
	}
	else {
		cout << "3이 존재하지 않음!" << endl;
	}

	auto it_lower = lower_bound(v.begin(), v.end(), 3);

	if (it_lower != v.end()) {
		printf("3 이상이 처음으로 나타나는 인덱스 위치: %d, 값: %d\n", distance(v.begin(), it_lower), *it_lower);
	}
	else {
		cout << "3 이상이 나타나는 위치를 찾지 못함!" << endl;
	}

	auto it_upper = upper_bound(v.begin(), v.end(), 3);

	if (it_upper != v.end()) {
		printf("3보다 큰 값이 처음으로 나타나는 인덱스 위치: %d, 값: %d\n", distance(v.begin(), it_upper), *it_upper);
	}
	else {
		cout << "3보다 큰 값이 나타나는 위치를 찾지 못함!" << endl;
	}

	return 0;
}
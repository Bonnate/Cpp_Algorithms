#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minTrucks = INT_MAX;

void backtrack(vector<int>& load, int index, int remaining, int trucks) {
	if (index == load.size()) {
		minTrucks = min(minTrucks, trucks);
		return;
	}

	if (remaining < load[index]) {
		minTrucks = min(minTrucks, trucks);
		return;
	}

	if (remaining >= load[index]) {
		backtrack(load, index + 1, remaining - load[index], trucks);
	}

	trucks++;
	backtrack(load, index + 1, remaining - load[index], trucks);
	trucks--;
}

int solution(int M, vector<int>& load) {
	sort(load.begin(), load.end(), greater<int>());

	backtrack(load, 0, M, 1);

	return minTrucks != INT_MAX ? minTrucks : -1;
}

int main() {
	int M = 10; // 최대 무게
	vector<int> load = { 2, 3, 7, 8 }; // 물건의 무게

	int minTrucks = solution(M, load);
	cout << "최소 트럭 수: " << minTrucks << endl;

	return 0;
}
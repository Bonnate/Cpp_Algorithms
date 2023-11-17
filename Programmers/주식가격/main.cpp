#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s;
	int n = prices.size();

	for (int i = 0; i < n; i++) {
		// 스택이 비어있지 않고 스택마지막 값이 현재값보다 크다면 -> 값이 떨어짐을 의미
		while (!s.empty() && prices[s.top()] > prices[i]) {
			// 가격이 떨어졌으므로 i - 스택마지막 값을 대입
			answer[s.top()] = i - s.top();
			s.pop();
		}
		// 현재 인덱스를 스택에 넣기
		s.push(i);
	}

	while (!s.empty()) {
		answer[s.top()] = n - s.top() - 1;
		s.pop();
	}

	return answer;
}

int main()
{
	solution({ 1, 2, 3, 2, 3 });
}
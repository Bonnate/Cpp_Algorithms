#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getTime(string format)
{
	return stoi(format.substr(0, 2)) * 60 + stoi(format.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
	// pair에 입실, 퇴실(청소 시간 포함)을 삽입
	vector<pair<int, int>> v;
	for (vector<string> s : book_time)
		v.push_back({ getTime(s[0]) , getTime(s[1]) + 10 });

	// 정렬 수행(입실 시간 오름차순)
	sort(v.begin(), v.end());

	// 우선순위 큐를 이용하여 검사
	priority_queue<int> q;
	for (int i = 0; i < v.size(); ++i)
	{
		// 큐에서 v[i].first(입장 시간)이 q.top 이상이라면?
		if (!q.empty() && -q.top() <= v[i].first)
			q.pop(); // 동일한 방을 사용 가능하기에 pop을 하여 큐에서 제거

		// 새로운 방 사용 (pop을 한 경우 호출되는경우에는, pop을 한 방을 청소 후 재사용
		q.push(-v[i].second);
	}

	// 큐의 size가 최소로 사용해야하는 방의 개수
	return q.size();
}

int main()
{
}
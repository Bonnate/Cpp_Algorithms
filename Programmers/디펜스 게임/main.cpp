#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
	int answer = 0;
	int sum = 0;
	priority_queue<int> q;

	int i = 0;
	// sum이 n을 초과하기 전까지 큐에 삽입
	for (; i < enemy.size(); ++i)
		if (sum + enemy[i] > n)
			break;
		else
		{
			sum += enemy[i];
			q.push(enemy[i]);
		}

	// 무적권을 모두 사용할때까지 검사
	for (; i < enemy.size() && k; ++i)
	{
		// 큐에 삽입
		q.push(enemy[i]);
		sum += enemy[i];

		// sum이 n을 초과(병사가 부족한경우)
		if (sum > n)
		{
			// k(무적권)을 사용하여 가장 병사가 많이 필요한 경우 제거
			sum -= q.top();
			q.pop();
			++answer;
			--k;
		}
	}

	// q에 남아있는 수 더하기
	answer += q.size();

	// 무적권을 모두 사용했을때, 나머지 라운드를 최대한 시도
	for (; i < enemy.size(); ++i)
	{
		// 병사 수가 초과되었다면 끝내기
		if (sum + enemy[i] > n)
			break;

		sum += enemy[i];
		++answer;
	}

	return answer;
}

int main()
{
	//solution(7, 3, { 4, 2, 4, 5, 3, 3, 1 });
	//solution(2, 4, { 3, 3, 3, 3 });
	//solution(5, 5, { 5, 5, 5, 5, 5, 1, 1, 1, 1, 1 });
	//solution(5, 5, { 1, 1, 1, 1, 1, 5, 5, 5, 5, 5 });
	//solution(1, 1, { 1, 2 });
	//solution(3, 2, { 1, 1, 1, 100, 100, 100 });
	//solution(199, 1, { 99, 99, 1, 101 });
	//solution(1, 2, { 2, 1, 2, 1 });
	//solution(5, 2, { 99, 1, 99 });
}
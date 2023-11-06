#include <string>
#include <vector>
using namespace std;

vector<int> arr(11);
vector<int> answer{ -1 };
int maxScore = -1;

void DFS(int l, int n, vector<int> info) {
	if (l == 11)
	{
		int score = 0;
		for (int i = 0; i < 10; ++i)
		{
			if (info[i] < arr[i])
				score += (10 - i);
			else if (info[i])
				score -= (10 - i);
		}

		// 점수가 같을때, 더 낮은 점수를 맞추면 갱신
		if (maxScore <= score && score > 0)
		{
			// 점수가 갱신되는경우에는 바로 변경
			if (maxScore != score)
			{
				answer = arr;
				maxScore = score;
			}
			// 같은 점수일경우, 가장 낮은 점수를 맞추는 조건을 검사
			else
			{
				for (int i = info.size() - 1; i >= 0; --i)
				{
					// 서로 값이 다를때, answer의 값이 더 크다면, 변경해서는 안됨(낮은 점수를 많이 맞춘것)
					if (arr[i] != answer[i])
						if (answer[i] > arr[i])
							return;
						else
							break;
				}

				answer = arr;
			}
		}
	}
	else
	{
		for (int i = n; i >= 0; --i)
		{
			arr[l] = i;
			DFS(l + 1, n - arr[l], info);

			if (l == 10)
				break;
		}
	}
}

vector<int> solution(int n, vector<int> info) {
	DFS(0, n, info);
	return answer;
}

int main(int argc, const char* argv[]) {
	//solution(5, { 2,1,1,1,0,0,0,0,0,0,0 });
	//solution(1, { 1,0,0,0,0,0,0,0,0,0,0 });
	//solution(9, { 0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1 });
	solution(10, { 0,0,0,0,0,0,0,0,3,4,3 });

	return 0;
}
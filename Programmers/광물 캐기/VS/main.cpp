#include <string>
#include <vector>
using namespace std;

int sel; // 선택해야 하는 개수
int ch[10]; // 선택 배열
bool used[10]; // 해당 id를 사용했는지 체크
int answer = 99999; // answer
int stamina[3][3]{ {1, 1, 1},{5, 1, 1},{25, 5, 1} }; // 각 곡괭이로 캐는 광물의 피로도 소모량

void DFS(vector<int> v1, vector<int> v2, int s)
{
	if (s == sel)
	{
		int sum = 0;

		// sel만큼 반복하여
		for (int i = 0; i < sel; ++i)
		{
			// 각 곡괭이마다 최대 5개씩 광물을 캠
			for (int j = 0; j < 5; ++j)
			{
				// 만약 광물의 최대 개수를 넘어가면 리턴
				if (i * 5 + j >= v2.size())
					break;

				// 각 곡괭이의 채굴 피로도만큼을 더하기
				sum += stamina[v1[ch[i]]][v2[i * 5 + j]];
			}
		}

		// 정답을 갱신 (최소값)
		answer = min(answer, sum);
	}
	else
	{
		// 0부터 sel만큼 반복하여
		for (int i = 0; i < sel; ++i)
		{
			// used[i]를 사용하지 않았다면
			if (!used[i])
			{
				used[i] = true; // 사용 체크
				ch[s] = i; // 선택ch에 i를 등록
				DFS(v1, v2, s + 1); // DFS
				used[i] = false; // DFS가 끝나면 사용 체크 해제
			}
		}
	}
}

int solution(vector<int> picks, vector<string> minerals)
{
	// 선택해야하는 개수는 광물의 개수(5배수) 만큼
	sel = minerals.size() / 5 + (minerals.size() % 5 == 0 ? 0 : 1);

	// v1은 가장 좋은 곡괭이를 사용하도록 정렬
	vector<int> v1;
	for (int i = 0; i < sel; ++i)
	{
		// 다이아몬드 곡괭이부터 삽입 시도
		if (picks[0] > 0)
		{
			--picks[0];
			v1.push_back(0);
		}
		else if (picks[1] > 0)
		{
			--picks[1];
			v1.push_back(1);
		}
		else if (picks[2] > 0)
		{
			--picks[2];
			v1.push_back(2);
		}
	}

	// sel은 곡괭이에 개수에 맞게 재정렬될 수 있음
	// (광물이 11개, 곡괭이가 2개인경우 sel은 2로 재설정)
	sel = v1.size();

	// v2는 stamina 배열에서 빠르게 접근하기 위해 int로 변환
	vector<int> v2;
	for (string s : minerals)
	{
		if (s == "diamond")
			v2.push_back(0);
		else if (s == "iron")
			v2.push_back(1);
		else
			v2.push_back(2);
	}
	DFS(v1, v2, 0);

	return answer;
}

int main()
{
	solution({ 0, 1, 1 }, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
}
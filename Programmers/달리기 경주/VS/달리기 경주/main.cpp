#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
	vector<string> answer;

	// 두개의 map을 사용하여 swap
	unordered_map<int, string> m1;
	unordered_map<string, int> m2;

	// map에 모든 정보 삽입
	for (int i = 0; i < players.size(); i++)
	{
		m1[i] = players[i];
		m2[players[i]] = i;
	}

	// calling 만큼 반복
	for (int i = 0; i < callings.size(); i++)
	{
		// 현재 이름을 가리키는 인덱스 번호를 빠르게 가져오기
		int currentIdx = m2[callings[i]];

		// callings[1]보다 한칸 앞에 있는 대상을 가져오기
		string change = m1[currentIdx - 1];

		// m1을 앞뒤로 변경
		m1[currentIdx - 1] = callings[i];
		m1[currentIdx] = change;

		// m2를 앞뒤로 변경
		m2[callings[i]] = currentIdx - 1;
		m2[change] = currentIdx;
	}

	// foreach문은 삽입했던 순서대로 리턴하기에 1등부터 삽입
	for (pair<int, string> p : m1)
	{
		cout << p.second << endl;
		answer.push_back(p.second);
	}

	return answer;
}

int main(int argc, const char* argv[]) {
	solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

	return 0;
}
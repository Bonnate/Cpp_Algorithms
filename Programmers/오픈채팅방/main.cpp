#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	unordered_map<string, string> users;

	for (int i = 0; i < record.size(); ++i)
	{
		istringstream iss(record[i]);
		vector<string> input{ istream_iterator<string>(iss), istream_iterator<string>() };

		if (input[0][0] == 'E')
		{
			if (users.find(input[1]) == users.end())
			{
				users.insert({ input[1], input[2] });
			}
			else
			{
				users[input[1]] = input[2];
			}

			answer.push_back("{" + input[1] + "}님이 들어왔습니다.");
		}
		else if (input[0][0] == 'L')
		{
			answer.push_back("{" + input[1] + "}님이 나갔습니다.");
		}
		else
		{
			users[input[1]] = input[2];
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		int startPos = answer[i].find("{");
		int endPos = answer[i].find("}", startPos);

		if (startPos != string::npos && endPos != string::npos && startPos < endPos)
		{
			// "{" 다음 문자부터 "}" 직전 문자까지 추출
			string uid = answer[i].substr(startPos + 1, endPos - startPos - 1);

			// users에서 검색하여 replace
			if (users.find(uid) != users.end())
				answer[i].replace(startPos, endPos - startPos + 1, users[uid]); // 대체
		}
	}

	return answer;
}

int main()
{
	vector<string> a = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });

	for (string s : a)
		cout << s << endl;
}
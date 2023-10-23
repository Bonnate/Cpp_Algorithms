#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter)
{
	vector<string> result; // 결과를 리턴할 string 벡터
	stringstream ss(input); // sstream
	string token; // split된 문자열을 임시로 담을 토큰

	// getline 함수로 받아온 후 벡터에 삽입
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
};

vector<int> solution(vector<string> park, vector<string> routes)
{
	vector<int> answer;

	int width = park[0].size();
	int height = park.size();

	int row = 0, col = 0;
	for (int i = 0; i < park.size(); ++i)
		for (int j = 0; j < park[0].size(); ++j)
			if (park[i][j] == 'S')
			{
				row = i, col = j;
				break;
			}

 	for (string s : routes)
	{
		vector<string> splited = split(s, ' ');
		int move = stoi(splited[1]);
		bool moved = true;

		if (splited[0] == "N")
		{
			for (int i = 0; i < move; ++i)
			{
				if (row - 1 - i < 0 || park[row - 1 - i][col] == 'X')
				{
					moved = false;
					break;
				}
			}

			if (moved)
				row -= move;
		}
		else if (splited[0] == "S")
		{
			for (int i = 0; i < move; ++i)
			{
				if (row + 1 + i >= height || park[row + 1 + i ][col] == 'X')
				{
					moved = false;
					break;
				}
			}

			if (moved)
				row += move;
		}
		if (splited[0] == "W")
		{
			for (int i = 0; i < move; ++i)
			{
				if (col - 1  - i < 0 || park[row][col - 1 - i ] == 'X')
				{
					moved = false;
					break;
				}
			}

			if (moved)
				col -= move;
		}
		else if (splited[0] == "E")
		{
			for (int i = 0; i < move; ++i)
			{
				if (col + 1 + i >= width || park[row][col + 1 + i] == 'X')
				{
					moved = false;
					break;
				}
			}

			if (moved)
				col += move;
		}
	}

	answer.push_back(row);
	answer.push_back(col);

	return answer;
}

int main()
{
	/*
	S : 시작 지점
	O : 이동 가능한 통로
	X : 장애물
	*/

	//solution({ "SOO","OOO","OOO" }, { "E 2", "S 2", "W 1" });
	//solution({ "SOO","OXX","OOO" }, { "E 2", "S 2", "W 1" });
	solution({ "OSO", "OOO", "OXO", "OOO" }, { "E 2", "S 3", "W 1" });
}
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

struct line
{
	char owner;
	int startRow;
	int startCol;
	int endRow;
	int endCol;

	int distance()
	{
		return startRow == endRow ? endCol - startCol + 1 : endRow - startRow + 1;
	}

	int verticalDistance(line& ref)
	{
		return ref.startRow - startRow;
	}

	// 가로 모양으로 11자를 만족하는가?
	pair<int, int> hotizontalFit(line& ref)
	{
		if (ref.startRow - startRow < 2)
		{
			return { -1, -1 };
		}

		int iCol = 0, jCol = 0;
		iCol = max(startCol, ref.startCol); // 두 가로 영역 사이의 최대 겹치는 시작 부분
		jCol = min(endCol, ref.endCol); // 두 가로 영역 사이의 최대 겹치는 끝 부분

		return { iCol, jCol };
	}

	// 세로 모양으로 11자를 만족하는가?
	pair<int, int> verticalFit(line& ref)
	{
		if (ref.startCol - startCol < 2)
		{
			return { -1, -1 };
		}

		int iRow = 0, jRow = 0;
		iRow = max(startRow, ref.startRow); // 두 가로 영역 사이의 최대 겹치는 시작 부분
		jRow = min(endRow, ref.endRow); // 두 가로 영역 사이의 최대 겹치는 끝 부분

		return { iRow, jRow };
	}

	void print()
	{
		printf("%c %d %d %d %d\n", owner, startRow, startCol, endRow, endCol);
	}
};

int solution(vector<string> cells) {
	int row = cells.size();
	int col = cells[0].size();

	map<char, vector<line>> rowM, colM;
	int answer = -1;

	for (int i = 0; i < row; ++i)
	{
		int length = 1;
		char owner = cells[i][0];
		int startCol = 0;

		for (int j = 1; j < col; ++j)
		{
			if (owner == cells[i][j])
			{
				++length;
			}
			else
			{
				if (length > 2)
					rowM[owner].push_back({ owner, i, startCol, i, startCol + length - 1 });

				startCol = j;
				length = 1;
			}

			owner = cells[i][j];
		}

		if (length > 2)
			rowM[owner].push_back({ owner, i, startCol, i, startCol + length - 1 });
		length = 1;
	}

	for (int i = 0; i < col; ++i)
	{
		int length = 1;
		char owner = cells[0][i];
		int startRow = 0;

		for (int j = 1; j < row; ++j)
		{
			if (owner == cells[j][i])
			{
				++length;
			}
			else
			{
				if (length > 2)
					colM[owner].push_back({ owner, startRow, i, startRow + length - 1, i });

				startRow = j;
				length = 1;
			}

			owner = cells[j][i];
		}

		if (length > 2)
			colM[owner].push_back({ owner, startRow, i, startRow + length - 1, i });
		length = 1;
	}

	// cout<<"ROW"<<endl;
	// for(pair<char, vector<line>> pa : rowM)
	// {
	//     for(line v : pa.second)
	//         v.print();
	// }
	// cout<<"COL"<<endl;
	// for(pair<char, vector<line>> pa : colM)
	// {
	//     for(line v : pa.second)
	//         v.print();
	// }

	for (pair<char, vector<line>> p : rowM)
	{
		char owner = p.first;

		vector<line> lines = p.second;

		for (int i = 0; i < lines.size() - 1; ++i)
		{
			for (int j = i + 1; j < lines.size(); ++j)
			{
				pair<int, int> cols = lines[i].hotizontalFit(lines[j]);

				if (cols.first != -1)
				{
					for (line verticalLine : colM[owner])
					{
						if (lines[i].startCol > verticalLine.startCol || lines[i].endCol < verticalLine.endCol || lines[j].startCol > verticalLine.startCol || lines[j].endCol < verticalLine.endCol)
							continue;

						// 수직선의 위치
						int fitCol = verticalLine.startCol;

						// 최대 길이
						int maxDist = max(fitCol - cols.first, cols.second - fitCol) + 1;

						if (maxDist < 3)
							continue;

						// 수직선의 길이
						int verticalLength = lines[j].startRow - lines[i].startRow - 1;

						answer = max(answer, maxDist * 2 + verticalLength);
					}
				}
				else
					continue;
			}
		}
	}

	for (pair<char, vector<line>> p : colM)
	{
		char owner = p.first;
		vector<line> lines = p.second;

		for (int i = 0; i < (int)lines.size() - 1; ++i)
		{
			for (int j = i + 1; j < lines.size(); ++j)
			{
				pair<int, int> rows = lines[i].verticalFit(lines[j]);

				if (rows.first != -1)
				{
					for (line horizontalLine : rowM[owner])
					{
						if (lines[i].startRow > horizontalLine.startRow || lines[i].endRow < horizontalLine.endRow || lines[j].startRow > horizontalLine.startRow || lines[j].endRow < horizontalLine.endRow)
							continue;

						// 수평선의 위치
						int fitRow = horizontalLine.startRow;

						// 최대 길이
						int maxDist = max(fitRow - rows.first, rows.second - fitRow) + 1;

						if (maxDist < 3)
							continue;

						// 수평선의 길이
						int horizontalLength = lines[j].startCol - lines[i].startCol - 1;

						answer = max(answer, maxDist * 2 + horizontalLength);
					}
				}
				else
					continue;
			}
		}
	}

	return answer;
}

int main()
{
	solution({ "AAAA", "BBBB", "AAAA" });
}
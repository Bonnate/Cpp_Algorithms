#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    int leftTopRow = 65535, leftTopCol = 65535;
    int rightBottomRow = -65535, rightBottomCol = -65535;

    for (int i = 0; i < wallpaper.size(); ++i)
    {
        for(int j = 0; j < wallpaper[0].size(); ++j)
        { 
            // 해당 위치에 파일이 있다면?
            if (wallpaper[i][j] == '#')
            {
                leftTopRow = min(leftTopRow, i);
                leftTopCol = min(leftTopCol, j);

                rightBottomRow = max(rightBottomRow, i);
                rightBottomCol = max(rightBottomCol, j);
            }
        }
    }

    vector<int> answer;
    answer.push_back(leftTopRow);
    answer.push_back(leftTopCol);
    answer.push_back(rightBottomRow + 1);
    answer.push_back(rightBottomCol + 1);

    return answer;
}

int main()
{
    //solution({  ".#...", 
    //            "..#..", 
    //            "...#." });

    //solution({  "..........", 
    //            ".....#....", 
    //            "......##..", 
    //            "...##.....", 
    //            "....#....." });

    //solution({ ".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...." });
    solution({ "..", "#." });
}
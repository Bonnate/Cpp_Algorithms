#include <string>
#include <vector>
using namespace std;

vector<vector<bool>> ch;

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int solution(vector<vector<int>> board) {
    
    int n = board.size();
    int answer = pow(n, 2);
    
    ch = vector<vector<bool>>(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            // 해당 위치가 지뢰라면?
            if(board[i][j] == 1)
            {
                --answer;
                ch[i][j] = true;
                
                for(int k = 0; k < 8; ++k)
                {
                    int ii = i + dy[k];
                    int jj = j + dx[k];
                    
                    if(ii < 0 || jj < 0 || ii >= n || jj >= n)
                        continue;
                    
                    if(ch[ii][jj])
                        continue;
                    
                    if(board[ii][jj] == 0)
                    {
                        --answer;
                        ch[ii][jj] = true;
                    }

                }
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
//    solution({{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}});
    
    solution({
               {1, 0, 0, 0, 0},
               {0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0},
               {0, 0, 1, 1, 0},
               {0, 0, 0, 0, 1}
    });
    return 0;
}

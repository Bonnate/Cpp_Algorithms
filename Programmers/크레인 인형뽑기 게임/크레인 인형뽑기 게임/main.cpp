#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> s;
    
    vector<int> v(board.size(), 0);
    for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board.size(); ++j)
            if(board[j][i])
            {
                v[i] = j;
                break;
            }
            
    int answer = 0;
    for(int n : moves)
    {
        if(v[n - 1] == board.size())
            continue;
        
        int pos = v[n - 1]++;
        int doll = board[pos][n - 1];
        
        if(!s.empty())
            if(doll == s.top())
            {
                s.pop();
                answer += 2;
            }
            else
                s.push(doll);
        else
            s.push(doll);
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    solution({  {0,0,0,0,0},
                {0,0,1,0,3},
                {0,2,5,0,1},
                {4,2,4,4,2},
                {3,5,1,3,1}}, {1,5,3,5,1,2,1,4});
    return 0;
}

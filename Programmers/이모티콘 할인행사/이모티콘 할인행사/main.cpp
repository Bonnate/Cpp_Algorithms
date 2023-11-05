#include <string>
#include <vector>
using namespace std;

int sale[]{10, 20, 30, 40};

vector<int> ch;
vector<int> answer{ -1, -1 };

void DFS(vector<vector<int>> users, vector<int> emoticons, int l)
{
    if(l == emoticons.size())
    {
        int reg = 0;
        int earn = 0;
        
        for(int i = 0; i < users.size(); ++i)
        {
            int price = 0;
            for(int j = 0; j < ch.size(); ++j)
                if(users[i][0] <= sale[ch[j]]) // 할인율 이상인경우?
                    price += (int)(emoticons[j] / 100.0f * (100 - sale[ch[j]])); // 구매
            
            // 구매 가격이 user의 가격 이상이라면?
            if(price >= users[i][1]) ++reg; // 이모티콘 플러스 가입
            else earn += price; // 수익 더하기
        }
        
        if(answer[0] <= reg)
        {
            if(answer[0] < reg)
                answer[1] = 0;
            
            answer = max(answer, {reg, earn});
        }
    }
    else
    {
        for(int i = 0; i < 4; ++i)
        {
            ch[l] = i;
            DFS(users, emoticons, l + 1);
        }
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    ch = vector<int>(emoticons.size());
    
    DFS(users, emoticons, 0);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    solution({{40, 2900}, {23, 10000}, {11, 5200}, {5, 5900}, {40, 3100}, {27, 9200}, {32, 6900}}, {1300, 1500, 1600, 4900});
    
//    solution({{40, 10000}, {25, 10000}}, {7000, 9000});
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sel;
int ch[10];
bool used[10];
int answer = 99999;

int stamina[3][3]   {{1, 1, 1},
                    {5, 1, 1},
                    {25, 5, 1}};

void DFS(vector<int> v1, vector<int> v2, int s) {
    if (s == sel)
    {
        int sum = 0;
        for (int i = 0; i < sel; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(i * 5 + j >= v2.size())
                    break;
                
                sum += stamina[v1[ch[i]]][v2[i * 5 + j]];
            }
        }
        
        answer = min(answer, sum);
    }
    else
    {
        for (int i = 0; i < sel; ++i) 
        {
            if (!used[i]) 
            {
                used[i] = true;
                ch[s] = i;
                DFS(v1, v2, s + 1);
                used[i] = false;
            }
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    sel = minerals.size() / 5 + (minerals.size() % 5 == 0 ? 0 : 1);
    
    vector<int> v1;
    for(int i = 0; i < sel; ++i)
    {
        if(picks[0] > 0)
        {
            --picks[0];
            v1.push_back(0);
        }
        else if(picks[1] > 0)
        {
            --picks[1];
            v1.push_back(1);
        }
        else if(picks[2] > 0)
        {
            --picks[2];
            v1.push_back(2);
        }
    }
    
    sel = v1.size();
    
    vector<int> v2;
    for(string s : minerals)
    {
            if(s == "diamond")
                v2.push_back(0);
            else if(s == "iron")
                v2.push_back(1);
            else
                v2.push_back(2);
    }
    DFS(v1, v2, 0);
    
    return answer;
}

int main() {
    
//    solution({1, 3, 2}, {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"});
    
    solution({0, 1, 1}, {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"});
             
    return 0;
}

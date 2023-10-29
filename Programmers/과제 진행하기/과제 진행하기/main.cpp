#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

struct plan
{
    string name;
    int start;
    int playtime;
    
    plan(){}
    
    plan(string n, string s, string p)
    {
        name = n;
        start = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        playtime = stoi(p);
    }
    
    const bool operator < (const plan& ref) const
    {
        return start < ref.start;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    
    vector<plan> v; // 입력된 plan 관리
    unordered_map<string, int> m; // 정렬된 v에 대한 인덱스 번호 저장
    for(vector<string> s : plans)
        v.push_back({s[0], s[1], s[2]});

    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i)
        m[v[i].name] = i;
    
    stack<string> s;
    
    vector<string> answer;
    
    // 과제 검사
    for(int i = 0; i < v.size(); ++i)
    {
        int gap;
        if(i + 1 == v.size())
            gap = 1000000;
        else
            gap = v[i + 1].start - v[i].start;
        
        if(v[i].playtime <= gap) // 즉시 해결 가능한경우 ?
        {
            gap -= v[i].playtime; // 남은 시간 차감
            v[i].playtime = 0; // v[i]의 남은 시간은 0
            
            answer.push_back(v[i].name); // 즉시 정답에 삽입
            
            // 아직도 시간이 남은경우?
            while(gap > 0 && !s.empty())
            {
                plan top = v[m[s.top()]]; // 가장 최근에 삽입한 과제 가져오기
                
                if(top.playtime <= gap) // 남은 시간으로 해결 가능한경우 ?
                {
                    gap -= top.playtime; // 남은 시간 재계산
                    top.playtime = 0; // 최근 과제는 종료
                    answer.push_back(top.name); // 정답에 삽입
                    s.pop(); // 과제 제거
                }
                else // 남은 시간으로 해결 불가능한경우
                {
                    v[m[s.top()]].playtime -= gap; // playtime만 갱신
                    break;
                }
            }
        }
        else // 즉시 해결하지 못하는경우 ?
        {
            v[i].playtime -= gap; // 시간 소모
            s.push(v[i].name); // 나중에 할 과제에 추가
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    solution({{"A", "12:00", "30"}, {"B", "12:10", "20"}, {"C", "15:00", "40"}, {"D", "15:10", "30"}});
    
//    solution({{"1", "00:00", "30"}, {"2", "00:10", "30"}, {"3", "01:10", "100"},{"4", "02:10", "30"}, {"5", "23:59", "30"}});
    
//    solution({{"korean", "00:00", "30"}, {"english", "00:20", "30"}, {"math", "01:00", "30"}});
    
//    solution({{"a", "09:00", "30"}, {"b", "09:20", "10"}, {"c", "09:40", "10"}});
    
//    solution({{"1", "00:00", "30"}, {"2", "00:10", "40"}, {"3", "00:20", "10"}, {"4", "00:25", "10"}, {"5", "01:10", "10"}});
    
//    solution({{"1", "00:00", "30"}, {"2", "00:10", "10"}, {"3", "00:30", "10"}, {"4", "00:50", "10"}});
    
//    solution({{"1", "00:00", "30"}, {"2", "00:10", "40"}, {"3", "00:20", "10"}, {"4", "00:25", "10"}, {"5", "01:10", "10"}});
    
//    solution({{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}});
    
//    solution({{"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"}});
    
//    solution({{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}});
    
    return 0;
}

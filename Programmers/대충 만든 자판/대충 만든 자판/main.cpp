#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    
    // map을 이용하여 keymap 데이터를 정리
    unordered_map<char, int> m;
    for(string s : keymap)
        for(int i = 0; i < s.size(); ++i)
            if(m.find(s[i]) != m.end())
                m[s[i]] = min(m[s[i]], i + 1);   // 이미 값이 존재하는경우 더 작은 값으로 대치
            else
                m[s[i]] = i + 1; // 값이 없는경우, 새롭게 삽입
            
    vector<int> answer(targets.size(), 0);
    for(int i = 0; i < targets.size(); ++i)
        for(int j = 0; j < targets[i].size(); ++j)
            if(m.find(targets[i][j]) != m.end()) // keymap에 데이터가 있는경우, 해당 값으로 더하기
                answer[i] += m[targets[i][j]];
            else
            {
                answer[i] = -1; // keymap에 데이터가 없다면, 완성할 수 없는 문자
                break;
            }
            
    return answer;
}

int main(int argc, const char * argv[]) {
    
    
//    solution({"ABACD", "BCEFD"}, {"ABCD","AABB"});
    solution({"AA"}, {"B"});
    
    return 0;
}

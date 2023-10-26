#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> m;
    
    // 참가자 이름을 모두 담기, 동명이인은 개수 증가
    for(string s : participant)
        ++m[s];
    
    // 완주자 이름을 기반으로 감소
    for(string s : completion)
        --m[s];
    
    // p의 개수가 1 이상이라면, 완주하지 못한 사람
    for(pair<string, int> p : m)
        if(p.second > 0)
            return p.first;
    
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"});
    return 0;
}

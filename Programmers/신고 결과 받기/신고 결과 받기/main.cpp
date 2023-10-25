#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result; // 결과를 리턴할 string 벡터
    stringstream ss(input); // sstream
    string token; // split된 문자열을 임시로 담을 토큰

    // getline 함수로 받아온 후 벡터에 삽입
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    unordered_map<string, vector<string>> m1; // 대상을 신고한 사람들을 누적으로 담음
    unordered_map<string, bool> m2; // 신고자 -> 대상 조합이 이미 사용되었는지 검사 (중복 신고 배제)
    unordered_map<string, int> m3; // answer의 인덱스에 바로 접근하기위해 사용
    
    for(string s : id_list)
        m1[s];
    
    for(int i = 0; i < id_list.size(); ++i)
        m3[id_list[i]] = i;
    
    for(string s : report)
    {
        vector<string> splited = split(s, ' ');
        string from = splited[0];
        string to = splited[1];
        
        if(m2[s] == false) // from to 조합이 없는경우
        {
            m2[s] = true;
            m1[to].push_back(from); // m1[to]에 신고자 목록 추가
        }
    }
    
    vector<int> answer = vector<int>(id_list.size(), 0);
    
    for(pair<string, vector<string>> p : m1)
        if(p.second.size() >= k) // 대상이 정지 기준에 부합하는경우?
            for(string s : p.second)
                ++answer[m3[s]]; // p.first를 신고한 대상 1씩 증가

    return answer;
}

int main(int argc, const char * argv[]) {
    
//    solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2);
    
    solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"}, 3);
    
    
    return 0;
}

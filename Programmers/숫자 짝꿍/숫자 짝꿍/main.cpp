#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) {
    
    unordered_map<char, int> m1, m2;
    
    for(char c : X)
        ++m1[c];
    
    for(char c : Y)
        ++m2[c];
    
    string answer = "";
    
    for(int i = 9; i > 0; --i)
    {
        if(m1.find((char)i) != m1.end() && m2.find((char)i) != m2.end())
        {
            int cnt = min(m1[i], m2[i]);
            
            for(int i = 0; i < cnt; ++i)
                answer.push_back((char)i);
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    solution("12321", "42531");
    
    return 0;
}

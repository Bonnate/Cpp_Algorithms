#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string input, char delimiter)
{
    vector<string> result; // 결과를 리턴할 string 벡터
    stringstream ss(input); // sstream
    string token; // split된 문자열을 임시로 담을 토큰
    
    // getline 함수로 받아온 후 벡터에 삽입
    while(getline(ss, token, delimiter))
        result.push_back(token);
    
    return result;
};

vector<int> solution(string myString) {
    
    vector<int> answer;
    
    vector<string> splited = split(myString, 'x');
    for(string s : splited)
        answer.push_back(s.length());
    
    if(myString[myString.length() - 1] == 'x')
        answer.push_back(0);
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    solution("xabcxdefxghi");
    
    return 0;
}

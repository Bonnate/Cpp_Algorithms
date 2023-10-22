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

vector<string> solution(vector<string> quiz) {
    
    vector<string> answer;

    for(string str : quiz)
    {
        vector<string> splited = split(str, ' ');
        
        if(splited[1] == "+")
            answer.push_back(stoi(splited[0]) + stoi(splited[2]) == stoi(splited[4]) ? "O" : "X");
        else
            answer.push_back(stoi(splited[0]) - stoi(splited[2]) == stoi(splited[4]) ? "O" : "X");
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    
    solution({"3 - 4 = -3", "5 + 6 = 11"});
    
    return 0;
}

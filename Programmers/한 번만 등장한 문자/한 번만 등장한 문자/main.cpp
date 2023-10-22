#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    vector<pair<char, int>> characters;
    
    for(int i = 0; i < s.size(); ++i)
    {
        bool imported = false;
        for(int j = 0; j < characters.size(); ++j)
        {
            if(characters[j].first == s[i])
            {
                imported = true;
                ++characters[j].second;
            }
                
        }
        
        if(!imported)
            characters.push_back({s[i], 1});
    }
    
    string answer;
    for(int i = 0; i < characters.size(); ++i)
    {
        if(characters[i].second == 1)
            answer.push_back(characters[i].first);
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}

int main(int argc, const char * argv[]) {
    solution("abcabcadc");
    return 0;
}

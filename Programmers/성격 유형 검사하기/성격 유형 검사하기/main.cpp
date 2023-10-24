#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {

    unordered_map<char, int> m;

    for (int i = 0; i < survey.size(); ++i)
    {
        // 1 ~ 7
        int selection = choices[i];

        if (selection < 4)
            m[survey[i][0]] += (4 - selection);
        else if (selection > 4)
            m[survey[i][1]] += (selection - 4);
    }

    string answer = "";
    answer.push_back(m['R'] >= m['T'] ? 'R' : 'T');
    answer.push_back(m['C'] >= m['F'] ? 'C' : 'F');
    answer.push_back(m['J'] >= m['M'] ? 'J' : 'M');
    answer.push_back(m['A'] >= m['N'] ? 'A' : 'N');

    return answer;
}


int main() {
    solution({ "TR", "RT", "TR" }, { 7, 1, 3 });
}

#include <string>
#include <vector>

using namespace std;



string solution(vector<int> numbers, string hand) {
    
    vector<pair<int,int>> v
    {
        {3,1},
        {0,0}, {0,1}, {0,2},
        {1,0}, {1,1}, {1,2},
        {2,0}, {2,1}, {2,2},
    };
    
    pair<int, int> left = {3, 0};
    pair<int, int> right = {3, 2};
    
    string answer = "";
    for(int n : numbers)
    {
        if(n == 1 || n == 4 || n == 7)
        {
            left = v[n];
            answer.push_back('L');
            continue;
        }
        else if(n == 3 || n == 6 || n == 9)
        {
            right = v[n];
            answer.push_back('R');
            continue;
        }
        
        int distL = abs(left.first - v[n].first) + abs(left.second - v[n].second);
        int distR = abs(right.first - v[n].first) + abs(right.second - v[n].second);
        
        if(distL == distR)
            if(hand == "right")
            {
                right = v[n];
                answer.push_back('R');
            }
            else
            {
                left = v[n];
                answer.push_back('L');
            }
        else if(distL < distR)
        {
            left = v[n];
            answer.push_back('L');
        }
        else
        {
            right = v[n];
            answer.push_back('R');
        }
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    
    solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
    
    return 0;
}

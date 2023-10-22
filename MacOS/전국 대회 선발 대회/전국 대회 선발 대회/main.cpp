#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    
    int answer = 0;
    
    priority_queue<pair<int, int>> result;
    
    for(int i = 0; i < rank.size(); ++i)
        if(attendance[i])
            result.push({-rank[i], i});
    
    for(int i = 3; i > 0; --i)
    {
        answer += result.top().second * pow(10, i * 2 - 2);
        result.pop();
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {

    int sol = solution({1, 2, 3}, {true, true, true});
    
    
    return 0;
}

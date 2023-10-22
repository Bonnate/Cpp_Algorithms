#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int solution(vector<int> array) {
    
    map<int, int> m;
    for(int n : array)
        ++m[n];
    
    int maxValue = -1;
    int res = -1;
    for(const pair<int, int> p : m)
    {
        if(maxValue < p.second)
        {
            maxValue = p.second;
            res = p.first;
        }
    }
        
    
    int cnt = 0;
    for(const pair<int, int> p : m)
        if(p.second == maxValue)
            ++cnt;
        
    return cnt == 1 ?  res : -1;
}


int main(int argc, const char * argv[]) {
    
//    solution({1, 2, 3, 3, 3, 4});
    int res = solution({1, 1, 2, 2});
    
    return 0;
}

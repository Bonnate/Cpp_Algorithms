#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    
    int idx[1000000];
    
    int i = 0, answer = 0;
    for(int n : ingredient)
    {
        idx[i] = n;
        
        if(i >= 3)
            if(idx[i-3] == 1 && idx[i-2] == 2 && idx[i-1] == 3 && idx[i] == 1)
            {
                ++answer;
                i -= 4;
            }
        
        ++i;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    solution({1, 3, 2, 1, 2, 1, 3, 1, 2});
//    solution({2, 1, 1, 2, 3, 1, 2, 3, 1});
    return 0;
}

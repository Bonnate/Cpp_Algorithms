#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    
    int answer = 0;
    
    for(int i = 0; i < section.size(); ++i)
    {
        int select = section[i];

        while(true)
        {
            if(i + 1 == section.size())
                break;
            
            if(section[i + 1] > select + m - 1)
            {
                ++answer;
                break;
            }
            
            ++i;
        }
    }
    
    return ++answer;
}

int main(int argc, const char * argv[]) {
//    
//    printf("%d",     solution(8, 4, {2, 3, 6}));
//    printf("%d",     solution(5, 4, {1, 3}));
//    printf("%d",     solution(4, 1, {1, 2, 3, 4}));
    printf("%d",     solution(10, 3, {1, 3, 5, 7, 9}));

    
    return 0;
}

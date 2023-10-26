#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    sort(reserve.begin(), reserve.end());
    
    vector<bool> v(n, true);
    for(int num : lost)
        v[num - 1] = false;
    
    // 여유 체육복이 있는 사람이 체육복을 잃어버렸다면, 자기 자신에게 사용
    for(int i = reserve.size() - 1; i >= 0; --i)
        for(int j = 0; j < lost.size(); ++j)
            if(reserve[i] == lost[j]) // 자기 자신인경우?
            {
                //Vector은 iterator로 erase
                reserve.erase(reserve.begin() + i); // 더 이상 빌려주지 못함
                v[lost[j] - 1] = true; // 자기 자신은 체육복이 있음
                break;
            }
    
    // 양옆 학생들에게 체육복을 대여
    for(int num : reserve)
    {
        --num;
                
        // 왼쪽은 0 이상이어야하며, 체육복이 없어야 함
        if(num - 1 >= 0 && v[num - 1] == false)
        {
            v[num - 1] = true;
            continue;
        }
            
        // 오른쪽은 n-1 이하여야하며, 체육복이 없어야 함
        if(num + 1 <= n - 1 && v[num + 1] == false)
        {
            v[num + 1] = true;
            continue;
        }
    }

    int answer = 0;
    for(bool b : v)
        if(b)
            ++answer;
    
    return answer;
}

int main(int argc, const char * argv[]) {

//    solution(5, {2, 4}, {1, 3, 5});
//    solution(5, {1, 5}, {2});
//    solution(5, {2, 4}, {4});
//    solution(5, {1, 2, 5}, {1, 5});
//    solution(3, {3}, {1});
//    solution(5, {4, 5}, {3, 4});
//    solution(3, {2, 3}, {1, 2});
    solution(5, {1, 2, 3}, {2, 3, 4});
    
    
    return 0;
}

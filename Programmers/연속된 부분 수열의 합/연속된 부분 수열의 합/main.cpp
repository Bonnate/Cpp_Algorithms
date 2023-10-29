/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer {0, 1000000};
    
    for(int i = sequence.size() - 1; i >= 0; --i)
    {
        int sum = 0;
        
        for(int j = i; j >= 0; --j)
        {
            sum += sequence[j];
            
            if(sum == k && i - j <= answer[1] - answer[0])
            {
                answer[1] = i;
                answer[0] = j;
                break;
            }
            else if(sum > k)
            {
                break;
            }
        }
    }
    
    return answer;
}
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    
    vector<int> answer {0, 1000000};
    int p1 = 0, p2 = 0;
    int sum = 0;
    
    for(int i = 0; i < sequence.size(); ++i)
    {
        // p1은 먼저 나아가며 더함
        sum += sequence[p1++];
        
        // 만약 p1만큼 더한 값이 k보다 크다면?
        if(sum > k)
            while(sum - sequence[p2] >= k) // sum이 k 이하가 될때까지
                sum -= sequence[p2++]; // p2를 증가시키며 값을 빼줌
        if(sum == k) // 만약 sum == k일때
            if(answer[1] - answer[0] > p1 - 1 - p2) // p1과 p2의 간격이 answer보다 작다면?
                answer = { p2, p1 - 1 }; // 정답을 갱신 (연속된 수열의 길이가 짧음)
    }
    
    return answer;
}


int main(int argc, const char * argv[]) {
//    solution({2, 2, 2, 2, 2}, 6);
    solution({1, 1, 1, 2, 3, 4, 5}, 5);
//    solution({1, 2, 3, 4, 5}, 7);
    return 0;
}

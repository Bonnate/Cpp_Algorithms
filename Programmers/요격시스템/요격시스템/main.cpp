    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int solution(vector<vector<int>> targets) {
        
        // 오름차순 정렬
        sort(targets.begin(), targets.end());
            
        int answer = 1;
        for(int i = 0; i < targets.size(); ++i)
        {
            // 최대 요격 e좌표
            int last = targets[i][1];
            
            for(; i < targets.size(); ++i)
            {
                // 다음 위치의 s좌표가 last 이상이라면 함께 요격 불가능
                if(targets[i][0] >= last)
                {
                    ++answer, --i;
                    break;
                }
                
                // 최대 요격 좌표는 점점 줄어들을 수 있음
//                last = min(last, targets[i][1]);
            }
        }
        
        return answer;
    }

int main(int argc, const char * argv[]) {
//
//    printf("%d", solution({{4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4}}));
//    printf("%d", solution({{1, 2}, {2, 3}, {3, 4}, {4, 5}, {3, 100}, {100,101}, {1, 100}, {1, 100000000}, {0, 1}, {1, 2}}));
//    printf("%d", solution({{1, 4}, {1, 3}, {1, 5}}));
//    printf("%d", solution({{1, 2}, {2, 3}, {3, 4}, {4, 5}}));
//    printf("%d", solution({{1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}, {6, 8}, {7, 9}}));
//    printf("%d", solution({{1, 2}, {2, 3}, {1, 3}}));
//    
//    printf("%d", solution({{1, 5}, {2, 3}, {4, 5}}));
//    printf("%d", solution({{1, 10}, {2, 8}, {3, 11}, {10, 11}}));
//    
//    return 0;
}

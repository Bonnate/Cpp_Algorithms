#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> arr;

// Find
int Find(int n) {
    if (n == arr[n]) return n; // n번째 그룹에 바로 속해있는경우 리턴
    else return arr[n] = Find(arr[n]); // n번째 그룹에 바로 속하지 않은경우, DFS로 실제 속한 그룹을 찾기
}

// Union
void Union(int a, int b) {
    arr[Find(a)] = Find(b); // arr[a]는 이제부터 b그룹에 속함
    arr[Find(b)] = Find(a); // arr[a]는 이제부터 b그룹에 속함
}

int solution(vector<int> cards) {
    
    arr = vector<int>(cards.size() + 1);
    
    // 집합 정보 초기화
    for (int i = 1; i <= cards.size(); ++i)
        arr[i] = i;
    
    // 각 인덱스에서 가리키는 cards[i]번째 인덱스를 같은 그룹으로 묶기
    for(int i = 0; i < cards.size(); ++i)
        Union(cards[i], i + 1);
    
    // 그룹의 크기를 구하기 위해 map에 저장
    map<int, int> m;
    for(int i = 1; i <= cards.size(); ++i)
        ++m[arr[i]];
    
    // 우선순위 큐를 이용하여 내림차순 정렬
    priority_queue<int> q;
    for(pair<int, int> p : m)
        q.push(p.second);
    
    // 그룹의 사이즈가 1이라면 0 리턴
    if(q.size() == 1)
        return 0;
    
    // 그룹의 사이즈가 2이상이라면, 2개를 가져와 곱하여 리턴
    int answer = 1;
    for(int i = 0; i < 2; ++i)
    {
        answer *= q.top();
        q.pop();
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    solution({8,6,3,7,2,5,1,4});
//    solution({1, 4, 2, 3, 5});
//    solution({2, 3, 4, 5, 1});
    return 0;
}

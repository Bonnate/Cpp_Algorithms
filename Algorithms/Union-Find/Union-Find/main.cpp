#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

// n이 속한 그룹의 번호를 리턴
int Find(int n) {
    if(arr[n] == n) return n;
    else return arr[n] = Find(arr[n]);
}

// a와 b가 같은 그룹이 되도록 결합
void Union(int a, int b) {
    arr[Find(a)] = Find(b);
}

// 각 요소가 실제로 속한 그룹을 가리키도록 갱신
void Refresh()
{
    for(int i = 0; i < arr.size(); ++i)
        Find(i);
}

int main(int argc, const char * argv[]) {
    
    // 각 원소가 가리키는곳은 같은 그룹으로 결합(0번째 원소인 1은 0과 같은 그룹)
    vector<int> v = vector<int>{1, 5, 0, 4, 3, 2};
    arr = vector<int>(v.size());
    
    // 각 번호에 맞는 그룹으로 초기화
    for(int i = 0; i < v.size(); ++i)
        arr[i] = i;
    
    for(int i = 0; i < v.size(); ++i)
    {
        Union(v[i], i);
        for(int j = 0; j < v.size(); ++j)
            printf("%d ", arr[j]);
        printf("\n");
    }
    
    printf("갱신 후\n");
    Refresh();
    
    for(int j = 0; j < v.size(); ++j)
        printf("%d ", arr[j]);
    printf("\n");
    
    return 0;
}

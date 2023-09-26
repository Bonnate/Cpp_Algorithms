#include <iostream>
using namespace std;

void foo(int i, int j, int N)
{
    // 3*3의 크기에서 중심인경우 [1,1] 공백 출력
    if ((i / N) % 3 == 1 && (j / N) % 3 == 1)
    {
        cout << i << j << N;
        cout << ' ';
    }
    else
    {
        //중심이 아니고, 가장 작은 형태인경우 *을 출력한다.
        if (N / 3 == 0)
        {
            cout << '*';
        }
        else
        {
            //작은 문제로 분할한다.
            foo(i, j, N / 3);
        }
    }
}

int main()
{
    int N;

    cin >> N;

    //출력은 총 n^2번 한다. (정사각형 모양)
    // 2중 for문으로 foo를 실행하도록 한다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            foo(i, j, N);
        }
        cout << endl;
    }
}
#include <stdio.h>
#include <math.h>

int main()
{
	//에라토스테네스의 체에서 사용할 소수 판별을 할 배열
	bool* flag;

	//최소부터 최대까지 주어진 경우 입력하는 변수
	int m, n;

	//값 입력
	scanf_s("%d %d", &m, &n);

	//최대값까지 동적할당을통해 배열을 만든다.
	//new bool[]()로 Zero-initialized를 통해 false인 상태로 생성할 수 있다.
	//관련 주소 https://stackoverflow.com/questions/4262914/set-default-value-of-dynamic-array
	//이렇게 구현한 이유는 true로 시작할 수 있지만, O(n) 시간 복잡도로 굳이 true로 바꿔
	//불필요한 처리를 하는것이 비효율적이라 판단하였다.
	flag = new bool[n + 1]();

	//1은 소수가 아니다 -> 참으로 바꿔 출력되지 않게한다.
	flag[1] = true;
 
	//소수를 찾는데 최대값의 제곱근까지 검사한다.
	for (int i = 2; i <= sqrt(n); ++i)
	{
		//i가 소수인가?
		if(!flag[i])
		{
			//i에 n배는 모두 소수가 아니므로 true로 바꿔준다.
			for (int j = i * 2; j <= n; j += i)
			{
				flag[j] = true;
			}
		}
	}

	//true가 아닌 모든 값들이 소수가 아닌것으로 나타난다.
	for (int i = m; i <= n; ++i)
	{
		if (!flag[i]) printf("%d\n", i);
	}
}
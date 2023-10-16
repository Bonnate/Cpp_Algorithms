#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void D(int v)
{
	if (v > 7)
		return;
	else
	{
		// 전위 순회
		//printf("%d", v);

		D(v * 2);

		// 중위 순회
		//printf("%d", v);

		D(v * 2 + 1);

		// 후위 순회
		printf("%d", v);
	}
}

int main()
{
	D(1);
}
#include <iostream>
#include <vector>

using namespace std;

void vInsertForward(vector<int>& v, int num)
{
	for (int i = v.size() - 1; i > 0; --i)
		v[i] = v[i - 1];

	v[0] = num;
}

int vFind(vector<int> v, int num)
{
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == num)
			return i;

	return -1;
}

void vMoveForward(vector<int>& v, int idx)
{
	int temp = v[idx];

	for (int i = idx; i > 0; --i)
		v[i] = v[i - 1];

	v[0] = temp;
}

int main()
{
	int S, N, input;
	scanf_s("%d %d", &S, &N);

	vector<int> v(S);
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &input);

		int findIdx = vFind(v, input);

		if (findIdx == -1) // 벡터에서 input이 없다면?
			vInsertForward(v, input); // forward에 input 삽입
		else if (findIdx != 0) // 벡터에서 input을 찾았지만, 첫번째 위치가 아니라면?
			vMoveForward(v, findIdx); // 앞으로 당기기
	}

	for (int i = 0; i < S; ++i)
		printf("%d ", v[i]);
}
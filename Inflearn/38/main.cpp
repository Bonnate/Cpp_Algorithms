#include <iostream>
#include <vector>

int main()
{
	int N;
	scanf_s("%d", &N);

	std::vector<int> iSeq(N), res(N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &iSeq[i]);

	// 마지막은 항상 0 (N보다 큰 수가 앞에 올 수 없음)
	res[N - 1] = N;

	// 마지막에서 한칸 앞 부터 시작
	for (int i = N - 2; i >= 0; --i)
	{
		// iSeq[i]만큼 i + j번째에 있는 값을 오른쪽에 있는 값으로부터 가져옴
		for (int j = 0; j < iSeq[i]; ++j)
			res[i + j] = res[i + j + 1];

		res[i + iSeq[i]] = i + 1;
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", res[i]);
}
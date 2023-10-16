#include <iostream>
#include <vector>

std::vector<int> vMergeAscending(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> res(a.size() + b.size());

	int aIdx = 0, bIdx = 0;

	for (int i = 0; i < res.size(); ++i)
	{
		if (aIdx == a.size())
			for (int j = bIdx; j < b.size(); ++j)
				res[i++] = b[j];
		else if (bIdx == b.size())
			for (int j = aIdx; j < a.size(); ++j)
				res[i++] = a[j];
		else if (a[aIdx] == b[bIdx])
		{
			res[i] = a[aIdx++];
			res[++i] = b[bIdx++];
		}
		else
			res[i] = a[aIdx] < b[bIdx] ? a[aIdx++] : b[bIdx++];
	}

	return res;
}

int main()
{
	int N, M;
	scanf_s("%d", &N);
	std::vector<int> arrN(N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arrN[i]);

	scanf_s("%d", &M);
	std::vector<int> arrM(M);
	for (int i = 0; i < M; ++i)
		scanf_s("%d", &arrM[i]);

	std::vector<int> res = vMergeAscending(arrN, arrM);

	for (int i = 0; i < res.size(); ++i)
		printf("%d ", res[i]);
}
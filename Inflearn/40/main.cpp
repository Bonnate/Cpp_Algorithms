#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sort(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
		for (int j = 0; j < length - i - 1; ++j)
			if (arr[j + 1] < arr[j])
				swap(arr[j + 1], arr[j]);
}

int main()
{
	int N, M;
	//int arrN[30001], arrM[30001];

	int idxN = 0, idxM = 0;

	scanf_s("%d", &N);
	vector<int> arrN(N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arrN[i]);

	//sort(arrN, N);
	sort(arrN.begin(), arrN.end());

	scanf_s("%d", &M);
	vector<int> arrM(M);
	for (int i = 0; i < M; ++i)
		scanf_s("%d", &arrM[i]);

	//sort(arrM, M);
	sort(arrM.begin(), arrM.end());

	while (true)
	{
		// 두 수가 같은경우?
		if (arrN[idxN] == arrM[idxM])
		{
			printf("%d ", arrN[idxN]);
			++idxN, ++idxM;
		}
		else if (arrN[idxN] > arrM[idxM])
		{
			++idxM;
		}
		else if (arrN[idxN] < arrM[idxM])
		{
			++idxN;
		}

		if (idxN == N || idxM == M)
			break;
	}
}
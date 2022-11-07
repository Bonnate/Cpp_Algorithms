#include <iostream>
using namespace std;

int main()
{
	int mat[2][100][100];
	
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> mat[0][i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> mat[1][i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << mat[0][i][j] + mat[1][i][j] << ' ';
		}

		cout << endl;
	}
}
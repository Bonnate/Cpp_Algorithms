#include <iostream>
using namespace std;

int main()
{
	int mat[9][9];
	int max = -1;
	int row, col;

	for (int i = 0; i < 9; ++i)
	{
		for(int j = 0; j < 9; ++j)
		{
			cin >> mat[i][j];

			if (mat[i][j] > max)
			{
				max = mat[i][j];
				row = i; 
				col = j;
			}
		}
	}

	printf("%d\n", max);
	printf("%d %d", row + 1, col + 1);
}
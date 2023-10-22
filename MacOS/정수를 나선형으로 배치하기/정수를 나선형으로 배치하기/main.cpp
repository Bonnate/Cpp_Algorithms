#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> arr = vector<vector<int>>(n, vector<int>(n, 0));
    
    int dir = 0; // right, bottom, left, top
    int cnt = pow(n, 2);
    int num = 1;
    int row = 0, col = 0;
    
    arr[0][0] = 1;
    
    while(num <= cnt)
    {
        switch(dir)
        {
            case 0:
                while(col < n - 1 && arr [row][col + 1] == 0)
                {
                    arr[row][col++] = num++;
                }
                dir = 1;
                arr[row][col] = num++;
                ++row;
                break;
            case 1:
                while(row < n - 1 && arr [row + 1][col] == 0)
                {
                    arr[row++][col] = num++;
                }
                dir = 2;
                arr[row][col] = num++;
                --col;
                break;
            case 2:
                while(col >= 1 && arr [row][col - 1] == 0)
                {
                    arr[row][col--] = num++;
                }
                dir = 3;
                arr[row][col] = num++;
                --row;
                break;
            case 3:
                while(row >= 1 && arr [row - 1][col] == 0)
                {
                    arr[row--][col] = num++;
                }
                dir = 0;
                arr[row][col] = num++;
                ++col;
                break;
        }
    }

    return arr;
}

int main(int argc, const char * argv[]) {
    solution(6);
    return 0;
}

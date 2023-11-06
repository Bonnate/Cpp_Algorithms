#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
	long long answer = 0;
	for (int i = 0; i <= d; i += k)
		answer += (long long int)(sqrt(pow(d, 2) - pow(i, 2)) / k + 1);
	return answer;
}

int main()
{
	solution(1, 1000000);
}
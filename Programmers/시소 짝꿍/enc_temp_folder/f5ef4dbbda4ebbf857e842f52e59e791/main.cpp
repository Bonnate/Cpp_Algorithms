#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
	map<long long, long long> m;

	for (long long n : weights)
		++m[n];

	long long answer = 0;
	for (pair<long long, long long> p : m)
	{
		long long w = p.first; // weight
		long long c = p.second; // count

		if (c > 1)
			answer += (c * (c - 1) / 2);

		if (w * 3 % 2 == 0)
			if (m.find(w * 3 / 2) != m.end())
				answer += (m[w * 3 / 2] * c);
		if (w * 4 % 2 == 0)
			if (m.find(w * 4 / 2) != m.end())
				answer += (m[w * 4 / 2] * c);
		if (w * 4 % 3 == 0)
			if (m.find(w * 4 / 3) != m.end())
				answer += (m[w * 4 / 3] * c);
	}

	return answer;
}

int main()
{
	solution({ 100, 100, 100, 150, 150, 200 });
}
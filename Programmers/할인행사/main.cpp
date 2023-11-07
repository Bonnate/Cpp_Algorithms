#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool func(vector<int> number)
{
	for (int n : number)
		if (n)
			return false;

	return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;

	map<string, int> m;
	for (int i = 0; i < want.size(); ++i)
		m[want[i]] = i;

	int sum = 0;
	for (int n : number)
		sum += n;

	int i = 0;
	for (; i < discount.size() && i < sum; ++i)
		if (m.find(discount[i]) != m.end())
			--number[m[discount[i]]];

	if (func(number))
		++answer;

	for (; i < discount.size(); ++i)
	{
		if (m.find(discount[i - sum]) != m.end())
			++number[m[discount[i - sum]]];
		if (m.find(discount[i]) != m.end())
			--number[m[discount[i]]];

		if (func(number))
			++answer;
	}

	return answer;
}

int main()
{
	solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" });

	//solution({ "apple" }, { 11 }, { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" });
}
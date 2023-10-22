#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
		string input;
		getline(std::cin, input);

		for (char c : input)
		{
			if (c == '[')
				cout << '{';
			else if (c == ']')
				cout << '}';
			else cout << c;
		}

		cout << endl << endl << endl;
	}
}
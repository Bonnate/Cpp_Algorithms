#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>

using namespace std;

vector<string> solution(string my_string) {
	for (string::iterator it = my_string.begin(); it != my_string.end(); ++it) {
		if (*it == ' ')
			while (it != my_string.end())
				if (*(it + 1) != ' ')
					break;
				else
					my_string.erase(it);
	}

	istringstream iss(my_string);
	return vector<string>{ istream_iterator<string>(iss), {} };
}
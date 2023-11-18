#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "abc123def456ghi";

	string numbers;

	// 문자열에서 숫자만 추출하여 numbers에 저장
	for (char c : str)
		if (c >= '0' && c <= '9')
			numbers += c;

	// 추출된 숫자 출력
	cout << "추출된 숫자: " << numbers << endl;

	// string을 int로 변환
	stoi(numbers);

	return 0;
}
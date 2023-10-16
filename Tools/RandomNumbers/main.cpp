#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <filesystem>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

// 파일 이름을 생성하는 함수
string generateFilename(int creationType, bool isInteger, int count) {
	string creationTypeStr;
	if (creationType == 1) {
		creationTypeStr = "무작위";
	}
	else if (creationType == 2) {
		creationTypeStr = "오름차순";
	}
	else if (creationType == 3) {
		creationTypeStr = "내림차순";
	}

	string dataTypeStr = isInteger ? "정수" : "실수";

	string timestamp = to_string(time(0));
	return "RandomNumbers_" + creationTypeStr + "_" + dataTypeStr + "_" + timestamp + "_" + to_string(count) + "_" + ".txt";
}

int main() {
	// 현재 작업 디렉토리 얻기
	string currentDirectory = filesystem::current_path().string();

	// 시드(seed) 설정
	srand(static_cast<unsigned>(time(0)));

	int n;  // 생성할 난수 개수
	cout << "난수 개수를 입력하세요: ";
	cin >> n;

	// 최소값 및 최대값 입력
	double minValue, maxValue;
	cout << "최소값: ";
	cin >> minValue;
	cout << "최대값: ";
	cin >> maxValue;

	// 정수 또는 실수 여부 입력
	bool isInteger;
	cout << "정수로 생성하려면 1, 실수로 생성하려면 0을 입력하세요: ";
	cin >> isInteger;

	// 생성 속성 선택
	int creationType;
	cout << "속성 선택: (1) 무작위 (2) 오름차순 (3) 내림차순: ";
	cin >> creationType;

	// 파일 이름 생성
	string filename = generateFilename(creationType, isInteger, n);
	string filePath = currentDirectory + "\\" + filename;

	// 파일 열기
	ofstream outputFile(filePath);

	if (!outputFile) {
		cerr << "파일을 열 수 없습니다." << endl;
		return 1;
	}

	// 난수 생성 엔진 설정
	if (creationType == 1) {
		// 무작위 순서
		vector<double> random_numbers;
		if (isInteger) {
			uniform_int_distribution<int> distribution(static_cast<int>(minValue), static_cast<int>(maxValue));
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				int random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}
		}
		else {
			uniform_real_distribution<double> distribution(minValue, maxValue);
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				double random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}

			// 벡터를 무작위로 섞기
			random_device rd;
			shuffle(random_numbers.begin(), random_numbers.end(), mt19937(rd()));
		}

		for (int i = 0; i < n; i++) {
			outputFile << random_numbers[i];
			if (i < n - 1) {
				outputFile << ' ';
			}
		}
	}
	else if (creationType == 2) {
		// 오름차순
		if (isInteger) {
			uniform_int_distribution<int> distribution(static_cast<int>(minValue), static_cast<int>(maxValue));
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				int random_number = distribution(generator);
				outputFile << random_number;
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
		else {
			uniform_real_distribution<double> distribution(minValue, maxValue);
			mt19937 generator(time(0));
			vector<double> random_numbers;
			for (int i = 0; i < n; i++) {
				double random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}
			sort(random_numbers.begin(), random_numbers.end());

			for (int i = 0; i < n; i++) {
				outputFile << random_numbers[i];
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
	}
	else if (creationType == 3) {
		// 내림차순
		if (isInteger) {
			uniform_int_distribution<int> distribution(static_cast<int>(minValue), static_cast<int>(maxValue));
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				int random_number = distribution(generator);
				outputFile << random_number;
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
		else {
			uniform_real_distribution<double> distribution(minValue, maxValue);
			mt19937 generator(time(0));
			vector<double> random_numbers;
			for (int i = 0; i < n; i++) {
				double random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}
			sort(random_numbers.rbegin(), random_numbers.rend());

			for (int i = 0; i < n; i++) {
				outputFile << random_numbers[i];
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
	}

	// 파일 닫기
	outputFile.close();

	cout << "파일이 " << filename << "에 저장되었습니다." << endl;

	return 0;
}
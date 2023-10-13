#include <iostream>

int main(int argc, const char* argv[]) {

    // 주민등록번호 앞, 뒤 값
    int first, last;

    // 주민등록 번호를 포맷으로 입력 받기
    scanf("%d-%d", &first, &last);

    // birthYear은 first에서 앞 두글자
    int birthYear = first / 10000;
    // sex는 last에서 앞 한글자
    int sex = last / 1000000;

    // 성별 입력이 3, 4이면 2000년대생, 1, 2이면 1900년대생
    int age = 2019 - birthYear + 1 - (sex < 3 ? 1900 : 2000);
    bool isMale = sex % 2;

    printf("%d %c", age, isMale ? 'M' : 'W');

    return 0;
}
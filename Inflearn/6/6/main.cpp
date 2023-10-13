#include <iostream>

int main(int argc, const char* argv[]) {

    char str[50];
    scanf_s("%s", str, sizeof(str));

    int num = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] >= '0' && str[i] <= '9')
            if (num != 0 || str[i] != '0')
                num = num * 10 + str[i] - '0';

    int primeCnt = 0;
    for (int i = 1; i <= num; ++i)
        if (num % i == 0)
            ++primeCnt;

    printf("%d\n%d", num, primeCnt);

    return 0;
}
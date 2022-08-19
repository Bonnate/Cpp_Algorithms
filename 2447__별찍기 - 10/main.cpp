#include <iostream>

using namespace std;
int main()
{
    int n, t;

    cin >> n;

    cout << '[' << n / 10000 * 10000 << ']' << endl;

    t = n % 10000 / 1000;
    if (t != 0)
        cout << '[' << t * 1000 << ']' << endl;

    t = n % 1000 / 100;
    if (t != 0)
        cout << '[' << t * 100 << ']' << endl;

    t = n % 100 / 10;
    if (t != 0)
        cout << '[' << t * 10 << ']' << endl;

    t = n % 10;
    if (t != 0)
        cout << '[' << t << ']' << endl;
}
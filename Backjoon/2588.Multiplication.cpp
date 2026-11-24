#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a,b,bb;
    int b1, b2, b3;

    cin >> a >> b;
    bb=b;

    b1 = bb / 100;
    bb = bb % 100;
    b2 = bb / 10;
    bb = bb % 10;
    b3 = bb / 1;

    cout << a*b3 << '\n' << a*b2 << '\n' << a*b1 << '\n' << a*b;

    return 0;
}


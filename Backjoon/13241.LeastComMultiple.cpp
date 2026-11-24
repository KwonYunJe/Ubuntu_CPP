#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b, tmp, big, small;

    cin >> a >> b;

    big = max(a,b);
    small = min(a,b);

    while(small != 0){
        tmp = big % small;
        big = small;
        small = tmp;
    }

    cout << (a * b) / big;

    return 0;
}


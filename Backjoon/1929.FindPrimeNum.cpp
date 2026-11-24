#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    bool isPrime(long long n);

    int start, end;
    cin >> start >> end;

    for(long long i = start; i <= end; i++){
        if(isPrime(i)){
            cout << i << '\n';
        }
    }

    return 0;
}

bool isPrime(long long n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i * i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

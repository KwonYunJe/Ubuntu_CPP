#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    bool isPrime(long long n);

    while(true){
        int n = 0;
        int count = 0;
        cin >> n;
        if(n == 0){
            break;
        }

        for(int k = n+1; k <= 2*n; k++){
            if(isPrime(k)){
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}


bool isPrime(long long n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
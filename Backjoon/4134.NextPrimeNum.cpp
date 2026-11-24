#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//소수 판별 함수
bool isPrime(long long n){
    if(n < 2) return false;

    for(long long i = 2; i * i <= n ; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int t = 0 ; 
    cin >> t ;

    for(int i = 0 ; i < t ; i++){
        long long num = 0;
        cin >> num;

        while(!isPrime(num)){
            num++;
        }

        cout << num << '\n';
    }
    return 0;
}


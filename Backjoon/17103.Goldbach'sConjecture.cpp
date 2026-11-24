#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    bool isPrime(long long n);

    vector<bool> prime(1000001, true);

    prime[0] = false;
    prime[1] = false;

    int t = 0;
    cin >> t;

    for(int i = 2; i * i <= 1000000; i++){
        if(prime[i]){
            for(int j = i * i; j <= 1000000; j += i){
                prime[j] = false;
            }
        }
    }

    for(int i = 0 ; i < t; i++){
        int num = 0;
        int count = 0;
        cin >> num;

    for(int k = 2; k <= num/2; k++){
        if(prime[k] && prime[num-k]){
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
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i = 2 ; i <=n ; i++){
        bool isPrime = true;
        //제곱근까지만 계산
        for(int k = 2; 1LL * k * k <= i ; k++){
            //나누어 떨어지면 1과 본인 이외의 약수가 있다는 뜻이므로 거짓
            if(i%k == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            answer++;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution(10) << endl;
    return 0;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//a:교환에 필요한 빈병 개수
//b:교환해주는 개수
//n:현재 빈병 개수
int solution(int a, int b, int n) {

    int answer = 0;

    while(n >= a){
        answer += n / a * b;
        n = (n / a * b) + (n % a);
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    cout<< solution(2,1,20) << endl;
    cout<< solution(3,1,20) << endl; 
    return 0;
}

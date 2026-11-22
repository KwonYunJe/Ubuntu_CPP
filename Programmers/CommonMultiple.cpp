#include <iostream>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

int solution(int number, int n, int m){
    int answer = 0;
    
    if(number % n == 0 && number % m == 0){
        answer = 1;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a = solution(60, 2, 3);
    
    cout << a << endl;

    return 0;
}



#include <iostream>
#include <string>

using namespace std;

int solution(int a1, int a0, int c, int n0){
    int answer = 0;

    if(a1 <= c && a1 * n0 + a0 <= c * n0){
        answer = 1;
    }else{
        answer = 0;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int a1, a0, c, n0;

    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;

    cout << solution(a1, a0, c, n0) << endl;

    return 0;
}

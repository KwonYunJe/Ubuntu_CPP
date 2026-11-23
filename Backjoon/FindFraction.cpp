#include <iostream>
#include <string>

using namespace std;

string solution (int x){
    string answer = "";
    //몇번째 행/열 인지
    int num = 1;

    while(x > num){
        x -= num;
        num ++;
    }

    if(num % 2 == 1){
        answer += to_string(num - x + 1) + "/" + to_string(x);
    }else{
        answer += to_string(x) + "/" + to_string(num - x + 1);
    }
    
    return answer;
}

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;

    cout << solution(x) << endl;
    
    return 0;
}

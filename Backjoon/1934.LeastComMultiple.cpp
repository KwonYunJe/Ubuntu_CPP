#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> answer;

    int t = 0;
    cin >> t;

    for(int i = 0 ; i < t; i++){
        //a,b,큰수, 작은수, 나머지
        int a,b,big,small,rest;
        cin >> a >> b;

        big = max(a,b);
        small = min(a,b);

        //최대 공약수 구하기(유클리드 호제법)
        while(small != 0){
            rest = big % small;
            big = small;
            small = rest;
        }

        //최소 공배수 = a * b / 최대 공약수
        cout << (a*b)/big << '\n';
    }

    return 0;
}

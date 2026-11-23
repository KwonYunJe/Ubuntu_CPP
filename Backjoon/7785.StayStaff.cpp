#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{   
    //표준 입출력 동기화를 해제하여 성능 개선
    ios::sync_with_stdio(false);
    //입력전에 cout을 자동으로 비우는 연결을 해제
    cin.tie(nullptr);
    //set으로 선언, 내림차순
    set<string, greater<string>> answer;
    int log = 0;
    cin >> log;

    for(int i = 0 ; i < log; i++){
        string name, type;
        cin >> name >> type;

        if(type == "enter"){
            answer.insert(name);
        }else{
            answer.erase(name);
        }
    }

    for(const string& name : answer){
        //endl을 쓰는 것보다 \n으로 줄바꿈하는게 더 빠름
        //endl은 줄바꿈 문자를 출력 -> 출력버퍼를 비움 과정을 수행하는데 반복적으로 수행하면 시간이 지연될 수 있음.
        cout << name << '\n';
    }


    return 0;
}

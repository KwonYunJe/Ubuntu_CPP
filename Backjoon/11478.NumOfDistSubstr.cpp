#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    //표준 입출력 동기화를 해제하여 성능 개선
    ios::sync_with_stdio(false);
    //입력전에 cout을 자동으로 비우는 연결을 해제
    cin.tie(nullptr);

    string str = "";
    unordered_set<string> answer;

    cin >> str ;

    for(int i = 1 ; i <= str.size(); i++){
        for(int k = 0; k + i <= str.size(); k++){
            string sub = str.substr(k,i);
            answer.insert(sub);
        }
    }

    cout << answer.size();

    return 0;
}

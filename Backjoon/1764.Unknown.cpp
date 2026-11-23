#include <iostream>
#include <string>
#include <set>

using namespace std;
int main(int argc, char const *argv[])
{
    //표준 입출력 동기화를 해제하여 성능 개선
    ios::sync_with_stdio(false);
    //입력전에 cout을 자동으로 비우는 연결을 해제
    cin.tie(nullptr);

    //듣보잡 입력받을 set
    set<string> unknow;
    //정답을 담을 set
    set<string> answer;

    int m, n;

    cin >> m >> n;

    //첫번째 명단 저장
    for(int i = 0 ; i < m ; i++){
        string line;
        cin >> line;
        unknow.insert(line);
    }

    //두번째 명단 저장
    for(int i = 0; i < n ; i++){
        string line;
        cin >> line;
        auto it = unknow.find(line);
        //첫번째 명단중 중복이 있으면
        if(it != unknow.end()){
            //정답 set에 해당 이름 추가
            answer.insert(line);
        }
    }

    //개수를 출력 후 정답을 순차 탐색하며 출력
    cout << answer.size() << endl;
    for(const string& name : answer){
        cout << name << '\n';
    }

    
    return 0;
}

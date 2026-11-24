#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    //표준 입출력 동기화를 해제하여 성능 개선
    ios::sync_with_stdio(false);
    //입력전에 cout을 자동으로 비우는 연결을 해제
    cin.tie(nullptr);

    unordered_set<int> answer;

    int m,n;

    cin >> m >> n;

    //집합 A를 차례대로 저장
    for(int i = 0 ; i < m ; i++){
        int line = 0 ;
        cin >> line;
        answer.insert(line);
    }

    //집합 B를 차례대로 저장
    for(int i = 0 ; i < n ; i++){
        int line = 0 ;
        cin >> line;
        auto it = answer.find(line);
        //집합 B의 요소로 기존의 배열에서 삭제를 시도
        //삭제에 실패하면 중복되지 않는다는 뜻이므로 새 값을 insert
        //삭제에 실패하면 중복되므로 삭제
        if(answer.erase(line) == 0){
            answer.insert(line);
        }
    }

    //최종 set의 길이를 출력 
    cout << answer.size();

    return 0;
}

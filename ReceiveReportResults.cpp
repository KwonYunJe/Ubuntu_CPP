#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// id_list : 전체 사용자 ID 목록
// report  : 신고 기록 ("신고자ID 신고대상ID")
// k       : 계정 정지에 필요한 최소 신고 횟수
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    // 사용자 수만큼 정답 배열을 0으로 초기화
    // 각 인덱스는 id_list의 동일한 인덱스 사용자에게 발송할 메일 수
    for(int i = 0; i < id_list.size(); i++){
        answer.push_back(0);
    }

    // 전체 사용자 수
    int n = id_list.size();

    // 신고 관계를 저장하는 2차원 배열
    // p[신고자][신고대상] = 1이면 신고한 관계
    // 같은 사람을 여러 번 신고해도 1회만 인정
    // 기존 일반 배열 대신 C++17 표준을 지원하는 vector 사용
    vector<vector<int>> p(n, vector<int>(n, 0));

    // 사용자 ID를 배열 인덱스와 연결하는 해시 맵
    // 예: idIndex["muzi"] = 0
    // ID를 검색할 때 매번 id_list 전체를 탐색하지 않아도 됨
    unordered_map<string, int> idIndex;

    // 전체 사용자 ID를 순회하며 ID와 인덱스를 연결
    for(int i = 0; i < id_list.size(); i++){
        idIndex[id_list[i]] = i;
    }

    // 전체 신고 기록을 하나씩 처리
    for(int i = 0; i < report.size(); i++){

        // 첫 번째 공백 이전: 신고자 ID
        // 예: "muzi frodo" -> "muzi"
        string uid = report[i].substr(0, report[i].find(' '));

        // 첫 번째 공백 이후: 신고 대상 ID
        // 예: "muzi frodo" -> "frodo"
        string trg = report[i].substr(report[i].find(' ') + 1);

        // 신고자와 신고 대상의 인덱스 조회
        int row = idIndex[uid];
        int col = idIndex[trg];

        // 신고 관계 기록
        // += 1이 아닌 = 1을 사용하여 중복 신고 방지
        p[row][col] = 1;
    }

    // 사용자별로 신고당한 횟수 확인
    for(int i = 0; i < id_list.size(); i++){

        // i번 사용자가 신고당한 횟수
        int count = 0;

        // i번 사용자를 신고한 사람들의 인덱스 목록
        vector<int> rp;

        // 모든 사용자가 i번 사용자를 신고했는지 확인
        for(int j = 0; j < id_list.size(); j++){

            // p[j][i]는 j번 사용자가 i번 사용자를 신고했는지 의미
            // 행: 신고자, 열: 신고 대상
            if(p[j][i] != 0){

                // 신고당한 횟수 증가
                count++;

                // 신고한 사용자의 인덱스 저장
                rp.push_back(j);
            }
        }

        // i번 사용자가 k회 이상 신고당했다면 계정 정지
        if(count >= k){

            // i번 사용자를 신고했던 모든 사용자에게 메일 발송
            for(int j = 0; j < rp.size(); j++){

                // rp[j]는 신고자의 실제 인덱스
                // 해당 신고자가 받을 메일 횟수를 1 증가
                answer[rp[j]]++;
            }
        }
    }

    // id_list 순서대로 사용자별 메일 수 반환
    return answer;
}

int main(int argc, char const *argv[])
{
    // 테스트 코드를 작성할 수 있는 영역
    return 0;
}

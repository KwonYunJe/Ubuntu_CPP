
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> stageRate;

    sort(stages.begin(), stages.end());

    int remainMem = 0;

    for (int i = 1; i <= N; i++) {
        int stayMem = 0;

        // 현재 스테이지에 머물러 있는 사용자 수
        for (int j = remainMem; j < stages.size(); j++) {
            if (stages[j] == i) {
                stayMem++;
            } else {
                break;
            }
        }

        // 현재 스테이지에 도달한 사용자 수
        int reachedMem = stages.size() - remainMem;

        double rate = 0.0;

        // 도달한 사용자가 없으면 실패율은 0
        if (reachedMem > 0) {
            rate = (double)stayMem / reachedMem;
        }

        stageRate.push_back({i, rate});

        // 현재 스테이지에서 멈춘 사용자 제외
        remainMem += stayMem;
    }

    // 실패율 내림차순, 실패율이 같으면 스테이지 오름차순
    sort(stageRate.begin(), stageRate.end(),
        [](const pair<int, double>& a, const pair<int, double>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    );

    // 정렬된 스테이지 번호만 answer에 저장
    for (const auto& item : stageRate) {
        answer.push_back(item.first);
    }

    return answer;
}

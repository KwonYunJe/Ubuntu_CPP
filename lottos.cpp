#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2,0);

    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    long count = std::count(lottos.begin(), lottos.end(), 0);
    long dupl = 0;

    for(int i = 0 ; i < lottos.size() ; i++){
        if(lottos[i] != 0){
            for(int j = 0 ; j < win_nums.size(); j++){
                if(lottos[i] == win_nums[j]){
                    dupl ++;
                    break;
                }
            }
        }
    }

    // 최고 순위: 일치하는 번호 + 0의 개수
    answer[0] = min(6L, 7 - (dupl + count));

    // 최저 순위: 이미 일치하는 번호만 인정
    answer[1] = min(6L, 7 - dupl);

    return answer;
}
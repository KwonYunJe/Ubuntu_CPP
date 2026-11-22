
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> talk = {"aya", "ye", "woo", "ma"};

    for(int i = 0; i < babbling.size(); i++){
        string target = babbling[i];
        int last = -1;
        int pos = 0;
        bool valid = true;

        while(pos < target.length()){
            bool matched = false;

            for(int j = 0; j < talk.size(); j++){

                // 현재 위치에서 발음이 일치하는지 확인
                if(target.substr(pos, talk[j].length()) == talk[j]){
                    matched = true;

                    // 직전 발음과 같으면 발음 불가능
                    if(j == last){
                        valid = false;
                        break;
                    }else{
                        // 직전 발음 갱신
                        last = j;

                        // 일치한 발음의 길이만큼 이동
                        pos += talk[j].length();

                        // 다음 위치를 검사하기 위해 for문 종료
                        break;
                    }
                }
            }

            // 일치하는 발음이 없거나 연속 발음이면 종료
            if(!matched || !valid){
                valid = false;
                break;
            }
        }

        // 문자열 전체를 올바르게 발음했다면
        if(valid && pos == target.length()){
            answer++;
        }
    }

    return answer;
}

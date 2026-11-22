#include <string>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    int countX[10] = {0};
    int countY[10] = {0};
    int pairs[10] = {0};

    // 1. X에 등장하는 숫자 개수 세기
    for(int i = 0; i < X.length() ; i++){
        countX[(int)X[i] - '0']++;
    }

    // 2. Y에 등장하는 숫자 개수 세기
    for(int i = 0; i < Y.length() ; i++){
        countY[(int)Y[i] - '0']++;
    }

    // 3. 숫자 9부터 0까지 확인하기
    for(int i = 0 ; i < 10 ; i++){
        pairs[i] = countX[i] >= countY[i] ? countY[i] : countX[i]; 
    }

    // 공통 등장 횟수만큼 answer에 추가
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < pairs[i]; j++){
            answer += i + '0';
        }
    }

    // 4. 예외 처리
    // 공통 숫자가 없으면 "-1"
    if(answer.empty()){
        return "-1";
    }
    // 공통 숫자가 0뿐이면 "0"
    if(answer[0] == '0'){
        return "0";
    }


    return answer;
}
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    vector<int> arr;

    for(size_t i = 0; i < dartResult.size(); i++){

        if(isdigit(static_cast<unsigned char>(dartResult[i]))){

            // 10점인 경우 처리
            if(dartResult[i] == '1' &&
               i + 1 < dartResult.size() &&
               dartResult[i + 1] == '0'){

                arr.push_back(10);
                i++;
            }else{
                arr.push_back(dartResult[i] - '0');
            }

        }else{

            if(dartResult[i] == 'D'){
                arr.back() = pow(arr.back(), 2);

            }else if(dartResult[i] == 'T'){
                arr.back() = pow(arr.back(), 3);

            }else if(dartResult[i] == '*'){
                arr.back() *= 2;

                // 이전 점수가 있을 때만 적용
                if(arr.size() >= 2){
                    arr[arr.size() - 2] *= 2;
                }

            }else if(dartResult[i] == '#'){
                // 현재 점수만 음수로 변경
                arr.back() *= -1;
            }
        }
    }

    for(size_t i = 0; i < arr.size(); i++){
        answer += arr[i];
    }

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    int answer = 0;

    //학생 수만큼 배열 생성, 체육복을 갖고 있을 거라는 가정하에 1로 모두 초기화
    vector<int> students(n,1);
    
    //체육복을 더 가진 학생들 체육복 수 +1
    for(size_t i = 0; i < reserve.size() ; i++){
        students[reserve[i] - 1] ++;
    }

    //체육복 도난당한 학생들 체육복 수 -1
    for(size_t i = 0; i < lost.size() ; i++){
        students[lost[i] - 1] --;
    }

    //체육복 개수가 0개인 학생 앞 뒤로 체육복 2개를 가진 학생 존재시 나눔
    for(size_t i = 0 ; i < students.size() ; i++){
        if(students[i] == 0){
            if((int)i-1 >= 0 && students[(int)i-1] == 2){
                students[i] = 1;
                students[i-1] = 1;
            }else if((int)i+1 <= students.size() - 1 && students[(int)i+1] == 2){
                students[i] = 1;
                students[i+1] = 1;
            }
        }
    }

    //체육복 개수가 1개 이상인 개수 카운트
    for(int count : students){
        if(count >=1){
            answer++;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> lost = {2,4};
    vector<int> reserve = {1,3,5};
    cout << solution(5, lost, reserve) << endl;
    return 0;
}

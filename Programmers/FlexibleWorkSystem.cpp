#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    vector<vector<int>> result;

    //타임로그(사람수)만큼 반복
    for(int i = 0; i < timelogs.size() ; i++){
        //지각시간 계산
        int endTime = schedules[i] + 10;

        //60분이 넘으면 시각 1증가 처리, 24시가 넘으면 00시 처리
        if(endTime%100 >= 60){
            endTime = endTime + 40;
            if(endTime / 100 >= 24){
                endTime = (endTime / 100 - 24) + endTime % 100;
            }
        }

        //한 명의 일주일간 기록
        vector<int> oneResult;

        //지각시 0을 대입, 정시 출근시 1대입
        for(int j = 0 ; j < timelogs[i].size() ; j++){
            if(timelogs[i][j] <= endTime){
                oneResult.push_back(1);
            }else{
                oneResult.push_back(0);
            }
        }

        //일주일간 기록 저장
        result.push_back(oneResult);
        
    }

    for(int i = 0; i < schedules.size() ; i++){
        int success = 1;
        for(int j = 0 ; j < result[i].size() ; j++){

            int day = (startday + j - 1) % 7 + 1;
            if(day == 6 || day == 7){
                continue;
            }
            if(result[i][j] == 0){
                success = 0;
                break;
            }
        }
        answer += success;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

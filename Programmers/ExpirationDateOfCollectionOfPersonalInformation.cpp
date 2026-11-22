#include <string>
#include <vector>
#include <sstream>

using namespace std;

//오늘 날짜, 약관종류/유효기간, 가입날짜/약관종류 
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    for(int i = 0 ; i < privacies.size(); i++){
        //privacies를 stringstream으로 변환
        stringstream ss(privacies[i]);

        //날짜
        string date;
        //약관 타입
        char type;
        //기간
        int due;

        //띄어쓰기를 기준으로 앞은 date 뒤는 type에 저장
        ss >> date >> type;

        //타입별 기간을 정리
        for(int j = 0 ; j < terms.size() ; j++){
            //terms의 한 요소(string)의 0번째 요소가 특정 타입과 일치하면
            if(terms[j][0] == type){
                //그 요소를 stringstream변환하고
                stringstream termss(terms[j]);
                //버리는 문자열
                char offType;
                //각각 버리는 문자열과 기간에 저장
                termss >> offType >> due;
                break;
            }
        }

        //년,월,일 split
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));

        //월+기간(월)이 12보다 클 경우
        if(month + due > 12){
            //년을 하나 올린다.
            year += (month + due)/12;
            month = (month + due)%12;
        }

        //현재 년,월,일 split
        int todayYear = stoi(today.substr(0,4));
        int todayMonth = stoi(today.substr(5,2));
        int todayDay = stoi(today.substr(8,2));

        //현재 년도가 
        if(todayYear >= year && todayMonth >= month && todayDay > day){
            answer.push_back(i + 1);
        }

    }

    return answer;
}
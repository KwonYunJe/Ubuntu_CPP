#include <string>
#include <vector>
#include <sstream>

using namespace std;

//오늘 날짜, 약관종류/유효기간, 가입날짜/약관종류 
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    for(int i = 0 ; i < privacies.size(); i++){
        stringstream ss(privacies[i]);

        string date;
        char type;
        int due;

        ss >> date >> type;

        for(int j = 0 ; j < terms.size() ; j++){
            if(terms[j][0] == type){
                stringstream termss(terms[j]);
                char offType;
                termss >> offType >> due;
                break;
            }
        }

        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));

        if(month + due > 12){
            year += (month + due)/12;
            month = (month + due)%12;
        }

        int todayYear = stoi(today.substr(0,4));
        int todayMonth = stoi(today.substr(5,2));
        int todayDay = stoi(today.substr(8,2));

        if(todayYear >= year && todayMonth >= month && todayDay > day){
            answer.push_back(i + 1);
        }

    }

    return answer;
}
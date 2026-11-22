#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    //R / C / J / A
    //T / F / M / N

    unordered_map<char, int> type;
    type['R'] = 0;
    type['T'] = 0;
    type['C'] = 0;
    type['F'] = 0;
    type['J'] = 0;
    type['M'] = 0;
    type['A'] = 0;
    type['N'] = 0;

    for(int i = 0 ; i< survey.size(); i++){
        int score = abs(choices[i] - 4);
        char a;
        if(choices[i] / 4 > 0){
            a = survey[i][1];
        }else{
            a = survey[i][0];
        }
        type[a] += score;
    }

    answer += (type['R'] >= type['T'] ? 'R' : 'T') ;
    answer += (type['C'] >= type['F'] ? 'C' : 'F') ;
    answer += (type['J'] >= type['M'] ? 'J' : 'M') ;
    answer += (type['A'] >= type['N'] ? 'A' : 'N');

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> survey = {"AN", "CF", "MJ", "RT", "NA"}; 
    vector<int> choices = {5, 3, 2, 7, 5};

    cout << solution(survey, choices);

    return 0;
}



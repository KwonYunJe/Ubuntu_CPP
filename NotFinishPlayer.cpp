#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(size_t i = 0 ; i < completion.size() ; i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            break;
        }
    }

    if(answer.size() == 0){
        answer = participant[participant.size() -1];
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<string> participant ={"leo", "kiki", "eden"} ;
    vector<string> completion ={"eden", "kiki"} ;

    cout << solution(participant, completion);

    return 0;
}

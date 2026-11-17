#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {

    string stAnswer = "";
    int answer = 0;
    string words = "";

    for(size_t i = 0; i < s.length() ; i++){

        if(s[i] >= '0' && s[i] <= '9'){
            stAnswer += s[i];
        }else{
            words += s[i];
        }

        cout << "words : " + words << endl;

        if(words == "zero"){
            stAnswer += "0";
            words = "";
        }else if(words == "one"){
            stAnswer += "1";
            words = "";
        }else if(words == "two"){
            stAnswer += "2";           
            words = ""; 
        }else if(words == "three"){
            stAnswer += "3";  
            words = "";
        }else if(words == "four"){
            stAnswer += "4";  
            words = "";
        }else if(words == "five"){
            stAnswer += "5";  
            words = "";
        }else if(words == "six"){
            stAnswer += "6";  
            words = "";
        }else if(words == "seven"){
            stAnswer += "7";  
            words = "";
        }else if(words == "eight"){
            stAnswer += "8";  
            words = "";
        }else if(words == "nine"){
            stAnswer += "9";  
            words = "";
        }

        cout << "answer : " + stAnswer << endl;
    }

    answer = stoi(stAnswer);

    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution("one4seveneight") << endl;
    return 0;
}

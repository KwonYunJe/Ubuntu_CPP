#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    //1단계 : 대문자 -> 소문자 치환
    for(size_t i = 0 ; i < new_id.length() ; i++){
        if(new_id[i] >=65 && new_id[i] <=90){
            new_id[i] += 32;
        }
    }

    //2단계 : 특수문자 제거
    string filtered = "";

    for(size_t i = 0; i < new_id.length(); i++){
        char c = new_id[i];

        if((c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9') ||
            c == '-' ||
            c == '_' ||
            c == '.'){

            filtered += c;
        }
    }

    new_id = filtered;

    //3단계 : 중복 마침표 제거
    filtered = "";
    for(size_t i = 0 ; i < new_id.length(); i++){
        char c = new_id[i];

        if(filtered.length() != 0 && filtered[filtered.length() - 1] == '.' && c == '.'){
            continue;
        }else{
            filtered += c;
        }
    }

    new_id = filtered;

    //4단계 : 어두, 어미의 마침표 제거
    while(new_id[0] == '.'){
        new_id.erase(0, 1);
    }
    while(new_id[new_id.length()-1] == '.'){
        new_id.erase(new_id.length()-1, 1);
    }

    //5단계 : 빈 문자열 대입
    if(new_id.length() == 0){
        new_id += 'a';
    }

    //6단계 : 최대 길이 제한
    if(new_id.length() >= 16){
        new_id.erase(15, new_id.length() - 1);
    }

    //6.5단계 : 어미의 . 제거
    while(new_id[new_id.length()-1] == '.'){
        new_id.erase(new_id.length()-1, 1);
    }

    //7단계 : 최소 길이 제한
    if(new_id.length() <= 2){
        while (new_id.length() <= 2)
        {
            new_id += new_id[new_id.length() - 1];
        }
    }

    answer = new_id;

    return answer;
}

int main(int argc, char const *argv[])
{
    cout << solution("z-+.^.") << endl;
    return 0;
}


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//문자열, 스킵문자, 건너뛸 인덱스
string solution(string s, string skip, int index) {
    string answer = "";

    vector<int> s_int;
    vector<int> skip_int ;

    for(int i = 0 ; i < s.size(); i++){
        s_int.push_back(s[i]);
    }

    for(int i = 0 ; i < skip.size() ; i++){
        skip_int.push_back(skip[i]);
    }

    for(int i = 0 ; i < s_int.size() ; i++){
        int count = 0;
        while(count != index){
            //기본적으로 1증가
            s_int[i]++;

            //증가된 숫자가 ascii code 상 122번을 넘는다면 영어 소문자에서 벗어나므로 소문자 a로 되돌린다.
            if(s_int[i] > 122){
                s_int[i] -= 26 ;
            }

            //증가된 숫자가 skip에 포함된 경우 i의 카운트를 감소
            if(find(skip_int.begin(), skip_int.end(), s_int[i]) == skip_int.end()){
                count++;
            }

        }
        
    }

    for(int i = 0 ; i < s_int.size() ; i++){
        answer.push_back(s_int[i]);
    }
    

    return answer;
}
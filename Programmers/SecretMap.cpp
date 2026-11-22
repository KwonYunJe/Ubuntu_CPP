#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    //vector<vector<int>> map(n, vector<int>(n, 0)) ;

    // for(int i = 0 ; i < n ; i++){
    //     int target = arr1[i];

    //     for(int k = n - 1 ; k >= 0 ; k--){
    //         map[i][k] = target % 2;
    //         target = target / 2;
    //         if(target == 0){
    //             break;
    //         }
    //     }
    // }

    // for(int i = 0 ; i < n ; i++){
    //     int target = arr2[i];

    //     for(int k = n - 1 ; k >= 0 ; k--){

    //         int ord = target % 2;
    //         target = target / 2;

    //         if(map[i][k] == 0){
    //             map[i][k] = ord;
    //         }

    //         if(target == 0){
    //             break;
    //         }
    //     }
    // }

    // for(size_t i = 0 ; i < map.size() ; i ++){
    //     string line = "";
    //     for(size_t k = 0; k < map[i].size() ; k++){
    //         if(map[i][k] == 1){
    //             line += "#";
    //         }else{
    //             line += " ";
    //         }
    //     }
    //     answer.push_back(line);

    // }

    for(int i = 0 ; i < n ; i++){
        //비트OR 연산자 : 두 수를 2진수로 변경해서 자릿수를 비교한다. OR연산이므로 각 수의 자릿수 중 하나만 1이어도 1로 결정난다.
        //ex 110011 + 1010000 = 1110011
        int combined = arr1[i] | arr2[i];
        string line = "";

        //오른쪽에서 n번째 비트만 1인 2진수를 만들어서 비교한다.
        //1<<2 = 10 , 1<<3 = 100, 1<<4 = 1000 ...
        for(int j = n - 1 ; j >= 0; j--){
            //& : 비트AND 연산자 : 두 수를 2진수로 변경해서 자릿수를 비교한다. AND연산이므로 각 수의 자릿수 둘 다 1이어야 1로 결정난다.
            if(combined & (1 << j)){
                line += "#";
            }else {
                line += " ";
            }
        }
        answer.push_back(line);
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};

    vector<string> answer = solution(n, arr1, arr2);

    for(size_t i = 0 ; i < answer.size(); i++){
        cout << answer[i];
    }

    cout << endl;
    return 0;
}

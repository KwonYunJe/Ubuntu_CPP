#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(size_t i = 0 ; i < commands.size() ; i++){

        vector<int> cutArr;

        cout << "start : " << commands[i][0] - 1 << endl;
        cout << "end : " << commands[i][1] - 1 << endl;

        for(size_t j = commands[i][0] - 1 ; j < commands[i][1] ; j++){
            cout << "push back : " << array[j] << endl;
            cutArr.push_back(array[j]);
        }   

        sort(cutArr.begin(), cutArr.end());

        for(int i = 0 ; i < answer.size(); i++){
            cout << answer[i] << ", ";
        }

        cout << endl;

        answer.push_back(cutArr[commands[i][2] - 1]);

    }

    return answer;
}

int main(int argc, char const *argv[])
{
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands= {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> answer = solution(array, commands);

    for(int i = 0 ; i < answer.size(); i++){
        cout << answer[i] << ", " ;
    }

    cout << endl;

    return 0;
}

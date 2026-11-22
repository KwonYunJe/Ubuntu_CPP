#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {

    //
    sort(strings.begin(), strings.end(), [n](string a, string b){
        if(a[n] == b[n]){
            return a < b;
        }

        return a[n] < b[n];
    });

    return strings;
}

int main(int argc, char const *argv[])
{
    vector<string> strings = {"sun", "bed", "car"};
    int n = 1;
    vector<string> answer = solution(strings, n);

    for(size_t i = 0 ; i < answer.size(); i++){
        cout << answer[i] + ", ";
    }
    return 0;
}

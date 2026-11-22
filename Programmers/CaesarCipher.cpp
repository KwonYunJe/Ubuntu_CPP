#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = s;

    for (char &c : answer) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + n) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + n) % 26;
        }
    }

    return answer;
}

int main(int argc, char const *argv[])
{   
    string s = "z";
    int n = 1;
    cout << solution(s,n) << endl;
    return 0;
}

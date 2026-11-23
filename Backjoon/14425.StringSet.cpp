#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int answer = 0;

    map<string, int> s;

    int n, m;

    cin >> n >> m ;

    for(int i = 0; i < n ; i++){
        string line; 
        cin >> line;
        s.insert({line, i});
    }

    for(int k = 0 ; k < m ; k++){
        string line;
        cin >> line;
        if(s.find(line) != s.end()){
            answer++;
        }
    }

    cout << answer << endl;

    /* code */
    return 0;
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int N = 0;
    cin >> N;

    for(int i = 0; i < N ; i++){
        string line = "";
        stack<char> prts;
        bool valid = true;

        cin >> line;

        for(int k = 0 ; k < line.length(); k++){
            if(line[k]=='('){
                prts.push('(');
            }else{
                if(prts.empty()){
                    valid = false;
                    break;
                }else{
                    prts.pop();
                }
            }
        }

        if(prts.empty() && valid){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}

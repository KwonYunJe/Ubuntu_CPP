#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    string line;

    while(getline(cin, line)){
        if(line == "."){
            break;
        }

        stack<char> brackets;
        bool valid = true;

        for(char c : line){
            if(c == '(' || c == '['){
                brackets.push(c);
            }else if(c == ')' || c == ']'){
                if(brackets.size() == 0){
                    valid = false;
                    break;
                }else{
                    if((brackets.top() == '('&& c == ')')
                     || (brackets.top() == '['&& c == ']')){
                        brackets.pop();
                     }else{
                        valid = false;
                        break;
                     }
                }
            }
        }

        if(valid == true && brackets.empty()){
            cout << "yes" << '\n';
        }else{
            cout << "no" << '\n';
        }
    }
    return 0;
}

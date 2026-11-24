#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    
    int N = 0;
    stack<int> numStack;
    cin >> N;

    for(int i = 0; i < N ; i++){
        int order = 0;
        int num = 0;
        cin >> order;

        switch (order)
        {
        case 1:
            cin >> num;
            numStack.push(num);
            break;
        case 2:
            if(numStack.empty()){
                cout << -1 << '\n';
            }else{
                cout << numStack.top() << '\n';
                numStack.pop();
            }
            break;
        case 3:
            cout << numStack.size() << '\n';
            break;
        case 4:
            if(numStack.empty()){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
            break;
        case 5:
            if(numStack.empty()){
                cout << -1 << '\n';
            }else{
                cout << numStack.top() << '\n';
            }
            break;
        
        default:
            break;
        }

    }

    return 0;
}

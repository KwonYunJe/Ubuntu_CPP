#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    int N = 0;
    stack<int> money;

    cin >> N;

    for(int i = 0; i < N ; i++){
        int nm = 0;
        cin >> nm;

        if(nm == 0){
            money.pop();
        }else{
            money.push(nm);
        }
    }

    N = 0;

    while(!money.empty()){
        N += money.top();
        money.pop();
    }

    cout << N;

    return 0;
}


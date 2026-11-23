#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    unordered_map<int, int> cards;

    int m,n;

    cin >> m;

    for(int i = 0; i < m ; i++){
        int num = 0;
        cin >> num;
        cards[num]++;
    }

    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        int num = 0;
        cin >> num;
        auto it = cards.find(num);
        if(it != cards.end()){
            cout << it->second << ' ';
        }else{
            cout << "0 ";
        }
    }

    /* code */
    return 0;
}

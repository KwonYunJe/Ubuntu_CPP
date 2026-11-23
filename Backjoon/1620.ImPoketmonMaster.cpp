#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    int m, n;
    vector<string> pokemon;
    unordered_map<string, int> pokemonMap;

    cin >> m >> n;

    for(int i = 0 ;i < m ; i++){
        string name;
        cin >> name;
        //이름으로 인덱스
        pokemon.push_back(name);
        //인덱스로 이름
        pokemonMap[name] = i + 1;
    }

    for(int i = 0 ; i < n ; i++){
        string problem;
        cin >> problem;

        //인덱스가 주어질 때
        if(problem[0] >= '0' && problem[0] <= '9'){
            int index = stoi(problem) - 1;
            cout << pokemon[index] << '\n';
        //이름이 주어질 때
        }else{
            cout << pokemonMap[problem] << '\n';
        }
    }

    return 0;
}

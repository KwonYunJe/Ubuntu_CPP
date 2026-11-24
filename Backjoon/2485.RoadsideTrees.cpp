#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int t = 0;
    int lastPoint = 0;
    vector<int> dist;
    int divisor = 0;
    int answer = 0 ;

    cin >> t;

    for(int i = 0 ; i < t ; i ++){
        int num;
        cin >> num;

        if(i == 0){
            lastPoint = num;
        }else{
            dist.push_back(num - lastPoint);
            lastPoint = num;
        }
    }

    int m = max(dist[0], dist[1]);
    int n = min(dist[0], dist[1]);
    int rest = 0;

    while(n != 0){
        rest = m % n;
        m = n;
        n = rest;
    }

    divisor = m;

    for(int i = 2 ; i < dist.size(); i++){
        m = max(dist[i], divisor);
        n = min(dist[i], divisor);
        while(n != 0){
            rest = m % n;
            m = n;
            n = rest;
        }
        divisor = m;
    }

    for(int i = 0 ; i < dist.size(); i++){
        answer += (dist[i] / divisor) - 1;
    }

    cout << answer;

    return 0;
}

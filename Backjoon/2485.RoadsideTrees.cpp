#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    //테스트케이스 개수
    int t = 0;
    //이전 좌표
    int lastPoint = 0;
    //가로수 사이 거리 배열
    vector<int> dist;
    //최대공약수
    int divisor = 0;
    int answer = 0 ;

    cin >> t;

    //사이 거리 배열 채우기
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

    //첫번째 두번째 거리의 공약수 구하기
    int m = max(dist[0], dist[1]);
    int n = min(dist[0], dist[1]);
    int rest = 0;

    while(n != 0){
        rest = m % n;
        m = n;
        n = rest;
    }

    divisor = m;

    //이전 공약수와 다음 거리와의 공약수 구하기(반복)
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

    //모든 거리차이의 최대 공약수로 간격마다 몇개가 더 필요한지 계산
    for(int i = 0 ; i < dist.size(); i++){
        answer += (dist[i] / divisor) - 1;
    }

    cout << answer;

    return 0;
}

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    //지갑의 크기를 정렬해서 0번째 = 짧은 쪽, 1번째 = 긴 쪽으로 정함
    sort(wallet.begin(), wallet.end());

    //지폐의 작은 쪽이 지갑의 작은 면보다 크면
    //or
    //지폐의 큰 쪽이 지갑의 큰 면보다 크면
    while(min(bill[0], bill[1]) > wallet[0] || max(bill[0], bill[1]) > wallet[1]){
        //큰 면을 반으로 접는다.
        if(bill[0] > bill[1]){
            bill[0] /= 2;
        } else {
            bill[1] /= 2;
        }
        answer++;
    }

    return answer;
}
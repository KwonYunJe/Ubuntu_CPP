#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int solution(vector<vector<int>> signals) {
    int answer = 0;
    //사이클 담는 벡터
    vector<int>cycle;

    //사이클 벡터 초기화
    for(int col = 0 ; col < signals.size() ; col++){
        cycle.push_back(signals[col][0] + signals[col][1] + signals[col][2]);
    }

    //최소 공배수 구하기
    int limit = cycle[0];

    for (int i = 1; i < cycle.size(); i++) {
        limit = lcm(limit, cycle[i]);
    }
    
    //리미트까지 반복
    for(int i = 1 ; i <= limit ; i++){

        //모두 노란불인지 체크하는 플래그
        bool allY = true;

        //신호등 개수만큼 반복
        for(int col = 0; col < signals.size() ; col ++){
            //현재 시간 위치
            int pos = i % cycle[col];

            //현재 시간 위치가 0 이라면 실제로 0이 아니라 사이클의 마지막
            if(pos == 0){
                pos = cycle[col];
            }

            //현재 탐색중인 신호등이 노란불일 경우
            if(pos > signals[col][0] 
                && pos <= signals[col][0] + signals[col][1] ){

                //플래그를 참으로 변경
                allY = true;

            }else{
                //플래그를 거짓으로 변경 후 반복문 탈출(한 개라도 거짓일 경우 탐색중지)
                allY = false;
                break;
            }
        }

        //신호등 개수만큼 반복이 끝난 후 플래그가 참일 경우 탐색중지 후 카운트 반환
        if(allY == true){
            answer = i;
            break;
        }
    }

    //리미트까지 반복하던 중 노란불이 되는 경우가 없다면
    if(answer == 0){
        answer = -1;
    }

    return answer;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

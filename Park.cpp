#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    //돗자리 크기 내림차순 정렬
    sort(mats.begin(), mats.end(), greater<int>());

    //가로 축
    int rows = park.size();
    //세로 축
    int cols = park[0].size();

    //돗자리 크기 순차 탐색
    for (int i = 0; i < mats.size(); i++) {
        int size = mats[i];

        //탐색 시작점
        for (int y = 0; y <= rows - size; y++) {
            for (int x = 0; x <= cols - size; x++) {

                //반복 중단 플래그
                bool canPlace = true;

                //연속 탐색 반복
                for (int dy = 0; dy < size; dy++) {
                    for (int dx = 0; dx < size; dx++) {
                        //비어있지 않은 블럭을 만났을 경우
                        if (park[y + dy][x + dx] != "-1") {
                            //탐색 중단 및 탈출
                            canPlace = false;
                            break;
                        }
                    }

                    //탐색 중단 플래그 발생 시
                    if (!canPlace) {
                        break;
                    }
                }

                //탐색이 끝날 때 까지 중단 플래그가 서지 않으면 size의 돗자리를 펼 수 있음
                if (canPlace) {
                    return size;
                }
            }
        }
    }

    return -1;
}
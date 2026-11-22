#include <string>
#include <vector>

using namespace std;

enum time {
    addTime, minTime,
};

int changeToInteger(string time){

    int colon = time.find(':');
    string left = time.substr(0, colon);
    string right = time.substr(colon + 1);

    return stoi(left) * 60 + stoi(right) ;
}

string changeToTime(int time){
    string left = to_string(time / 60);
    string right = to_string(time % 60);

    if(left.length() == 1){
        left = "0" + left;
    }

    if(right.length() == 1){
        right = "0" + right;
    }

    return left + ":" + right;
}

bool isOpening(int pos, int op_start, int op_end) {
    return pos >= op_start && pos <= op_end;
}

//동영상 길이, 시작점, 오프닝 시작, 오프닝 끝, 커맨드 리스트
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    //각각 초로 변환
    int video_len_int = changeToInteger(video_len);
    int pos_int = changeToInteger(pos);
    int op_start_int = changeToInteger(op_start);
    int op_end_int = changeToInteger(op_end);

       for (int i = 0; i < commands.size(); i++) {
        // 1. 명령 실행 전 오프닝 체크
        if (isOpening(pos_int, op_start_int, op_end_int)) {
            pos_int = op_end_int;
        }

        string cmd = commands[i];

        // 2. 명령 실행
        if (cmd == "next") {
            pos_int += 10;
            if (pos_int > video_len_int) {
                pos_int = video_len_int;
            }
        }

        else if (cmd == "prev") {
            pos_int -= 10;
            if (pos_int < 0) {
                pos_int = 0;
            }
        }

        // 3. 명령 실행 후 오프닝 체크
        if (isOpening(pos_int, op_start_int, op_end_int)) {
            pos_int = op_end_int;
        }
    }

    //초를 분:초 문자열로 변경
    answer = changeToTime(pos_int);

    return answer;
}


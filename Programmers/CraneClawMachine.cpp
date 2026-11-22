#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    stack<int> bucket;

    for(size_t i = 0 ; i < moves.size() ; i++){
        int col = moves[i] - 1;

        for(size_t j = 0 ; j < board.size() ; j++){
            if(board[j][col] != 0){
                if(!bucket.empty() && bucket.top() == board[j][col]){
                    bucket.pop();
                    answer+=2;
                }else{
                    bucket.push(board[j][col]);
                }
                board[j][col] = 0;
                break;
            }
        }


    }

    return answer;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for(size_t i = 0 ; i < numbers.size() ; i++){
        for(size_t j = i+1 ; j < numbers.size() ; j++){
            int sum = numbers[i]+numbers[j];
            if(std::find(answer.begin(), answer.end(), sum) != answer.end()){
                continue;
            }else{
                answer.push_back(sum);
            }
        }   
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main(int argc, char const *argv[])
{   
    vector<int> numbers = {2,1,3,4,1};
    vector<int> result = solution(numbers);

    for(size_t i = 0 ; i < result.size() ; i++){
        cout << result[i] << ", ";
    }
    cout << endl;
    return 0;
}

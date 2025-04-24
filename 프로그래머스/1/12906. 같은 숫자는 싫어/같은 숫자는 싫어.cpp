#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prev = arr[0];
    for(int i = 0; i< arr.size(); i++){
        if(arr[i] == prev) continue;
        answer.push_back(prev);
        prev = arr[i];
    }
    
    if(answer.size() == 0) answer.push_back(prev);
    else if(prev != answer[answer.size() - 1]) answer.push_back(prev);

    return answer;
}
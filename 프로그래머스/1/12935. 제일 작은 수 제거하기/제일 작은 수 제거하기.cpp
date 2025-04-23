#include <string>
#include <vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1){
        answer.push_back(-1);
        return answer;
    }
    
    int minVal = INT_MAX, minIdx = 0;
    for(int i = 0; i< arr.size(); i++){
        if(minVal <= arr[i]) continue;
        minVal = arr[i];
        minIdx = i;
    }
    arr.erase(arr.begin() + minIdx);
    return arr;
}
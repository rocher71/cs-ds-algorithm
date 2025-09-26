#include <string>
#include <vector>
#include<queue>
using namespace std;
int ansCnt;

void bfs(vector<int> numbers, int target){
    queue<pair<int, int>> q;
    q.push({0 + numbers[0], 0});
    q.push({0 - numbers[0], 0});
    
    while(!q.empty()){
        int currSum = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        if(idx == numbers.size() - 1){
            if(currSum == target) ansCnt++;
            continue;
        }
        
        q.push({currSum + numbers[idx + 1], idx+1});
        q.push({currSum - numbers[idx + 1], idx+1});
    }
}

int solution(vector<int> numbers, int target) {
    bfs(numbers, target);
    return ansCnt;
}
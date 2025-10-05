#include <string>
#include <vector>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    for(int i : scoville) pq.push(i);
    
    while(pq.top() < k && pq.size() > 1){
        answer++;
        int curr = pq.top();
        pq.pop();
        int next = pq.top();
        pq.pop();
        
        int newScov = curr + next*2;
        pq.push(newScov);
        if(pq.top() >= k) break;
    }
    if(pq.size() == 1 && pq.top() < k) answer = -1;
    return answer;
}
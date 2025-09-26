#include <string>
#include <vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;

int answerDist = INT_MIN;
vector<int> g[20001];
int dist[20001];

void dijk(int n){
    fill(dist + 1, dist + n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        int currDist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        for(int i = 0; i< g[curr].size(); i++){
            int next = g[curr][i];
            
            if(dist[next] <= currDist +1) continue;
            
            pq.push({currDist + 1, next});
            dist[next] = currDist + 1;
            answerDist = max(dist[next], answerDist);
        }
    }
    return;
}


int solution(int n, vector<vector<int>> edge) {
    for(int i = 0; i< edge.size(); i++){
        int v1 = edge[i][0];
        int v2 = edge[i][1];
        
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dijk(n);
    
    sort(dist, dist + n + 1);
    
    
    int answerCnt = 0;
    
    for(int i = n; i >= 1; i--){
        if(dist[i] > answerDist) continue;
        if(dist[i] < answerDist) break;
        answerCnt++;
    }
    return answerCnt;
}
#include <string>
#include <vector>
#include <queue>
#include<iostream>
#define MAX 201
using namespace std;

int cnt, ans;
bool visit[MAX];
vector<int> graph[MAX];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i];
            
            if(visit[next]) continue;
            
            q.push(next);
            visit[next] = true;
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    cnt = n;
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt ; j++){
            if(i == j || computers[i][j] == 0) continue;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }
    
    for(int i = 0; i < cnt; i++){
        if(visit[i]) continue;
        ans++;
        
        bfs(i);
    }
    
    return ans;
}
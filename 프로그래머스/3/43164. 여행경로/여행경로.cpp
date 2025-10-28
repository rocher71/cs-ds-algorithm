#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<iostream>
#define MAX 100001
using namespace std;

int airportCnt, icnIdx, ticketsCnt;
vector<string>answer;
vector<pair<string, pair<int, bool>>> graph[MAX];
unordered_map<string, int> namesToIdx;
string idxToNames[MAX];

void dfs(int currIdx){
    answer.push_back(idxToNames[currIdx]);
    //for(string str : answer) cout << str << " ";
    //cout << "\n";
    if(answer.size() == ticketsCnt + 1) return;
    for(int i = 0; i< graph[currIdx].size(); i++){
        int nextIdx = graph[currIdx][i].second.first;
        if(graph[currIdx][i].second.second) continue;
        graph[currIdx][i].second.second = true;
        dfs(nextIdx);
        if(answer.size() == ticketsCnt + 1) return;
        graph[currIdx][i].second.second = false;
    }
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketsCnt = tickets.size();
    for(int i = 0; i < tickets.size(); i++){
        string from = tickets[i][0];
        string to = tickets[i][1];
        
        if(namesToIdx.find(from) == namesToIdx.end()){
            namesToIdx[from] = airportCnt;
            idxToNames[airportCnt++] = from;
        } 
        if(namesToIdx.find(to) == namesToIdx.end()){
            namesToIdx[to] = airportCnt;
            idxToNames[airportCnt++] = to;
        } 
        
        graph[namesToIdx[from]].push_back({to, {namesToIdx[to], false}});
        
    }
    icnIdx = namesToIdx["ICN"];
    
    for(int i = 0; i< airportCnt; i++) sort(graph[i].begin(), graph[i].end());
    dfs(icnIdx);
    
    return answer;
}
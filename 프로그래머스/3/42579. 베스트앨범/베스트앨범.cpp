#include <string>
#include <vector>
#include<algorithm>
#include<map>
#include<queue>
#include<iostream>
using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
unordered_map<string, int> m;
unordered_map<int, int> cntInserted;
vector<pair<int, pair<int, int>>> v;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    if(a.first > b.first) return true;
    if(a.first < b.first) return false;
    
    // 장르 같음
    if(a.second.first > b.second.first) return true;
    if(a.second.first < b.second.first) return false;
    
    // 장르, 재생 횟수 같음
    if(a.second.second > b.second.second) return false;
    return true;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i< genres.size(); i++) m[genres[i]] += plays[i];
    // for(int i = 0; i< genres.size(); i++) pq.push({m[genres[i]], {plays[i], i}});
    for(int i = 0; i< genres.size(); i++){
        v.push_back({m[genres[i]], {plays[i], i}});
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i = 0; i< v.size(); i++){
        if(cntInserted[v[i].first] >= 2) continue;
        cntInserted[v[i].first]++;
        answer.push_back(v[i].second.second);
    }
    
    return answer;
}
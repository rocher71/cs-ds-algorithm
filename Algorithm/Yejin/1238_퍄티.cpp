// https://www.acmicpc.net/problem/1238 Gold3
#include <iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

int n, m, x;
vector<pair<int, int>> graph[1001];

int dijkstra(int departure, int arrival){
    int dist[1001];
    fill_n(dist, n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, departure});

    while (!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(curr == arrival) return cost;

        for(long unsigned int i = 0; i<graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;

            if(dist[next] <= cost + nextCost) continue;
            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
        }
    }
}

int main(){
    cin >> n >> m >> x;
    for(int i = 0; i<m; i++){
        int from, to , cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    int greatest = 0;
    for(int i = 1; i<=n; i++){
        if(i == x) continue;
        int sum = dijkstra(i, x);
        sum += dijkstra(x, i);
        greatest = max(greatest, sum);
    }

    cout << greatest <<"\n";
}
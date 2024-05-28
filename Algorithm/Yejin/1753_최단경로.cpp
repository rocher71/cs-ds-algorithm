#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;

int v, e, departure;
vector<pair<int, int>> graph[20001];
int dist[20001];

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, departure});
    dist[departure] = 0;

    while (!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for(long unsigned int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;

            if(dist[next] <= cost + nextCost) continue; //등호 빠지면 런타임 오류 뜸!
            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
        }
    }
}

int main(){
    cin >> v >> e >> departure;
    for(int i = 0; i<e; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }
    fill_n(dist, v+1, INF);
    dijkstra();

    for(int i = 1; i<=v; i++){
        if(dist[i] == INF){
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
}

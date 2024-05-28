#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define INF 1e9
using namespace std;

int v, e, departure, arrival;
vector<pair<int, int>> graph[1001];
int dist[1001];

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, departure});
    dist[departure] = 0;

    while (!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(curr == arrival) break; //이게 빠지면 시간 초과 뜸

        for(long unsigned int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;

            if(dist[next] <= cost + nextCost) continue;
            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
        }
    }
}

int main(){
    cin >> v >> e;
    for(int i = 0; i<e; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }
    cin >> departure >> arrival;
    fill_n(dist, v+1, INF);
    dijkstra();

    cout << dist[arrival]<< "\n";
}

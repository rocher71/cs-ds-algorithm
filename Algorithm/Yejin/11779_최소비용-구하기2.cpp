#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int n, m, departure, arrival;
vector<pair<int, int>> graph[1001];
int dist[1001];
vector<int> route[1001];

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, departure});
    dist[departure] = 0;
    route[departure].push_back(departure);

    while (!pq.empty()){
        //auto [cost, curr] = pq.top();
        int curr = pq.top().second;
        int cost = pq.top().first;

        if(curr == arrival) break;
        pq.pop();

        for(long unsigned int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;
            if(dist[next] <= cost + nextCost) continue;

            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
            route[next] = route[curr];
            route[next].push_back(next);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i <m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }
    cin >> departure >> arrival;
    fill_n(dist, n+1, INF);

    dijkstra();

    cout << dist[arrival] <<"\n" << route[arrival].size() <<"\n";
    for(int i = 0; i<route[arrival].size() - 1; i++){
        cout << route[arrival][i] <<" ";
    }
    cout << route[arrival][route[arrival].size()-1] <<"\n";
}
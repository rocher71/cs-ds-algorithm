#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int n, e, v1, v2;
vector<pair<int, int>> graph[801];

int dijkstra(int departure, int arrival){
    int dist[801];
    fill_n(dist, n + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, departure});
    dist[departure] = 0;

    while (!pq.empty()){
        int curr = pq.top().second;
        int cost = pq.top().first;
        if(curr == arrival) return cost;
        pq.pop();

        for(long unsigned int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;
            if(dist[next] <= cost + nextCost) continue;

            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
        }
    }
    return -1;
}

int main(){
    cin >> n >> e;
    for(int i = 0;i <e; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
    cin >> v1 >> v2;

    int route1 = 0, // 1 -> v1 -> v2 -> N
        route2 = 0, // 1 -> v2 -> v1 -> N
        oneToV1 = dijkstra(1, v1),
        oneToV2 = dijkstra(1, v2),
        v1ToN = dijkstra(v1, n),
        v2ToN = dijkstra(v2, n);

    if(oneToV1 == -1 || v2ToN == -1) route1 = -1;
    if(oneToV2 == -1 || v1ToN == -1) route2 = -1;

    if(route1 + route2 == -2){
        cout << -1 <<"\n";
        return 0;
    }


    int v1ToV2 = dijkstra(v1, v2);
    if(v1ToV2 == -1){
        cout << -1 << "\n";
        return 0;
    }
    route1 = (route1 != -1) ? oneToV1 + v2ToN : -1;
    route2 = (route2 != -1) ? oneToV2 + v1ToN : -1;

    if(route1 == -1){
        cout << route2 + v1ToV2 << "\n";
        return 0;
    }
    if(route2 == -1){
        cout << route1 + v1ToV2 << "\n";
        return 0;
    }
    cout << min(route1, route2) + v1ToV2 <<"\n";
    return 0;



}
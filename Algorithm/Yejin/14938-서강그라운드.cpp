#include<iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int n, range, r, answer = 0;
vector<pair<int, int>> graph[101];
int item[101];

// 출발점이 departure일 때 조건을 만족하는 item값의 합을 출력
int dijkstra(int departure){
    int dist[101];
    fill_n(dist, n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, departure});
    dist[departure] = 0;
    while (!pq.empty()){
        auto [cost, curr] = pq.top();
        pq.pop();

        for(long unsigned int i = 0; i< graph[curr].size(); i++){
            auto [next, nextCost] = graph[curr][i];
            if(dist[next] <= cost + nextCost) continue;
            if(cost + nextCost > range) continue;
            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
        }
    }

    int sum = 0;
    for(int i = 1;i <= n; i++){
        if(dist[i] > range ) continue;
        sum += item[i];
    }
    return sum;
}

int main(){
    cin >> n >> range >> r;
    for(int i = 1; i<=n; i++){
        cin >> item[i];
    }
    for(int i = 0; i < r ; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    for(int i = 1; i<= n; i++){
        answer = max(answer, dijkstra(i));
    }

    cout << answer <<"\n";

}
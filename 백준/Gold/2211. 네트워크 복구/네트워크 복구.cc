//2211 네트워크 복구
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define INF 1e9
using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int dist[1001];
//vector<int> route[1001];
vector<int> route[1001];
set<pair<int, int>> finalRoute;

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    route[1].push_back(1);

    while (!pq.empty()){
        auto [cost, curr] = pq.top();
        pq.pop();

        for(long unsigned int i = 0; i< graph[curr].size(); i++){
            auto [next, nextCost] = graph[curr][i];
            if(dist[next] <= cost + nextCost) continue;

            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
            route[next] = route[curr];
            route[next].push_back(next);
        }
    }
}

int main(){
    cin >>  n >>m;
    for(int i = 0; i<m; i++){
        int a, b, cost;
        cin >> a >> b>> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    fill_n(dist, n + 1, INF);

    dijkstra();

    for(int i = 1 ; i<= n; i++){
        for(long unsigned int j = 0; j < route[i].size()-1 ; j++){
            finalRoute.insert({route[i][j], route[i][j+1]});
        }
        /*
        int size = route[i].size();
        for(int j = 0; j < size - 1; j++){
            set<int>::iterator it = route[i].begin();
            finalRoute.insert({*it, *(++it)});
            route[i].erase(route[i].begin());
        }
         */
    }

    cout << finalRoute.size() <<"\n";
    for(set<pair<int, int>>::iterator it = finalRoute.begin(); it != finalRoute.end(); it++) {
        cout << it->first <<" " << it->second<<"\n";
    }
}
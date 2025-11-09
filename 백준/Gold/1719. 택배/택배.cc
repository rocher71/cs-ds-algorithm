#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int firstRoutes[1001][1001];
int dist[1001];

void dijk(int start){
    fill_n(dist, n + 1, INT_MAX);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {start, -1}});

    while(!pq.empty()){
        int cost = pq.top().first;
        int curr = pq.top().second.first;
        int firstRoute = pq.top().second.second;
        pq.pop();

        if(curr != start && firstRoutes[start][curr] == 0){
            firstRoutes[start][curr] = firstRoute;
        }

        for(int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;

            if(dist[next] <= cost + nextCost) continue;

            dist[next] = cost + nextCost;
            if(firstRoute == -1) pq.push({dist[next], {next, next}});
            else pq.push({dist[next], {next, firstRoute}});

        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(int i = 1; i<= n; i++) dijk(i);

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(i == j) cout << "- ";
            else cout << firstRoutes[i][j] << " ";
        }
        cout << "\n";
    }
}
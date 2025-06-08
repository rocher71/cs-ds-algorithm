#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define MAX 1001

int n, m, x;
vector<pair<int, int>> g[MAX];
int dist[MAX];

void dijk(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[x] = 0;
    pq.push({0, x});

    while(!pq.empty()){
        int currCost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(currCost != dist[curr]) continue;

        for(int i = 0; i< g[curr].size(); i++){
            int next = g[curr][i].first;
            int nextCost = g[curr][i].second;

            if(dist[next] <= currCost + nextCost) continue;

            dist[next] = currCost + nextCost;
            pq.push({dist[next], next});
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;
    for(int i = 0; i< m; i++){
        int a, b, cost;
        cin >> a >> b >>cost;
        g[a].push_back({b, cost});
        g[b].push_back({a, cost});
    }

    fill_n(dist, n + 1, INT_MAX);
    dijk();

    sort(dist + 1, dist + n + 1);

    cout << dist[n] * 2 << "\n";
}
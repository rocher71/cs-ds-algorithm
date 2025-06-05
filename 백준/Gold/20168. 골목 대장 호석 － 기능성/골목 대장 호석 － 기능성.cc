#include<iostream>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

int n, m, from, to, c;
vector<pair<int, int>> g[11];
int maxSuchi[11], cost[11];

void dijk(){
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pq.push({{0, 0}, from});
    maxSuchi[from] = 0;

    while(!pq.empty()){
        int currSuchi = pq.top().first.first;
        int currMoney = pq.top().first.second;
        int curr = pq.top().second;
        pq.pop();


        for(int i = 0; i< g[curr].size(); i++){
            int next = g[curr][i].first;
            int nextMoney = g[curr][i].second;
            int nextSuchi = max(currSuchi, nextMoney);

            if(currMoney + nextMoney > c || maxSuchi[next] <= nextSuchi) continue;

            maxSuchi[next] = nextSuchi;
            pq.push({{nextSuchi, currMoney + nextMoney}, next});

        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> from >> to >> c;
    for(int i = 0; i< m; i++){
        int a, b, cost;
        cin >> a >> b >>cost;
        g[a].push_back({b, cost});
        g[b].push_back({a, cost});
    }

    fill_n(maxSuchi, n + 1, INT_MAX);
    dijk();

    if(maxSuchi[to] == INT_MAX) cout << "-1\n";
    else cout << maxSuchi[to] << "\n";

}
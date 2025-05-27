#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#define MAX 101
using namespace std;

int tc;
int dist[MAX], distSum[MAX];
vector<pair<int, int>> g[MAX];

void dijk(int from, int n) {
    fill_n(dist, n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[from] = 0;
    pq.push({ 0, from });

    while (!pq.empty()) {
        int currCost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (currCost != dist[curr]) continue;

        for (int i = 0; i < g[curr].size(); i++) {
            int next = g[curr][i].first;
            int nextCost = g[curr][i].second;

            if (dist[next] <= currCost + nextCost) continue;

            dist[next] = currCost + nextCost;
            pq.push({ dist[next], next });
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) distSum[i] = INT_MAX;
        if (distSum[i] == INT_MAX) continue;

        distSum[i] += dist[i];
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> tc;

    while (tc--) {
        int n, m, k;
        cin >> n >> m;
        
        fill_n(distSum, n + 1, 0);
        for (int i = 1; i <= n; i++) g[i].clear();
        

        for (int i = 0; i < m; i++) {
            int a, b, cost;
            cin >> a >> b >> cost;
            g[a].push_back({ b, cost });
            g[b].push_back({ a, cost });
        }

        cin >> k;
        vector<int> friends(k);
        for (int i = 0; i < k; i++) cin >> friends[i];

        for (int i = 0; i < k; i++) dijk(friends[i], n);

        int minRoomNum = n + 1, minSum = INT_MAX;

        for (int i = 1; i <= n; i++) {

            if (minSum <= distSum[i]) continue;
            if (minSum == distSum[i] && minRoomNum < i)  continue;
            minSum = distSum[i];
            minRoomNum = i;
        }

        cout << minRoomNum << "\n";
    }
}
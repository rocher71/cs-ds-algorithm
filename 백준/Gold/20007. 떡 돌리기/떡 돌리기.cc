#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int n, m, x, y;
long long dist[1001];
vector<pair<int, int>> g[1001];

void dijk() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, y });
    dist[y] = 0;

    while (!pq.empty()) {
        long long currCost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (currCost != dist[curr]) continue;

        for (int i = 0; i < g[curr].size(); i++) {
            int next = g[curr][i].first;
            long long nextCost = g[curr][i].second;

            if (dist[next] <= currCost + nextCost) continue;

            dist[next] = currCost + nextCost;
            pq.push({ dist[next], next });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x >> y;

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        g[a].push_back({ b, cost });
        g[b].push_back({ a, cost });
    }

    fill_n(dist, n + 1, INT_MAX);
    dijk();

    sort(dist, dist + n);

   //     for(int i = 0; i < n ; i++) cout << dist[i] << " ";
     //   cout << "\n";

    long long days = 0, currDist = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] == 0) continue;
        if (dist[i] == INT_MAX || dist[i] * 2 > x) {
            currDist = 0;
            days = 0;
            break;
        }
        currDist += dist[i] * 2;
        if (currDist <= x) continue;
        currDist = dist[i] * 2;
        days++;
    }
    if (currDist != 0) days++;

    if (days == 0) cout << "-1\n";
    else cout << days << "\n";

    return 0;
}

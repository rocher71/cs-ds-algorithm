#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#define MAX 100001
using namespace std;

int n, m;
bool isVisible[MAX];
long long dist[MAX];
vector<pair<int, int>> v[MAX];

void dijk() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int curr = pq.top().second;
        long long currCost = pq.top().first;
        pq.pop();

        // 최단거리가 기록 되기 전에 큐에 삽입된 경우
        if (currCost != dist[curr]) continue;
        if (curr == n - 1) return;

        for (int i = 0; i < v[curr].size(); i++) {
            int next = v[curr][i].first;
            long long nextCost = v[curr][i].second;

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

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> isVisible[i];
    isVisible[n - 1] = false;
    // 문제에서 마지막 분기점은 무조건 상대의 시야에 보인다고 했으나, 
    // 방문 처리를 해야하므로 false로 변경

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        // 시야에 보이는, 즉 가지 못하는 분기점을 포함하는 간선은 굳이 저장하지 않음
        if (isVisible[a] || isVisible[b]) continue;
        v[a].push_back({ b, cost });
        v[b].push_back({ a, cost });
    }

    fill_n(dist, n, LLONG_MAX);

    dijk();

    if (dist[n - 1] == LLONG_MAX) cout << "-1\n";
    else cout << dist[n - 1] << "\n";

    return 0;
}
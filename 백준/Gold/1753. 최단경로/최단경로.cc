#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int v, e, start;
vector<pair<int, int>> graph[20001];
int dist[20001];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first;
			int nextCost = graph[curr][i].second;
			
			if (dist[next] <= cost + nextCost) continue;
			
			pq.push({ cost + nextCost, next });
			dist[next] = cost + nextCost;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> v >> e >> start;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	fill_n(dist, v + 1, INT_MAX);

	dijkstra();

	for (int i = 1; i <= v; i++) {
		if (dist[i] >= INT_MAX) {
			cout << "INF\n";
			continue;
		}
		cout << dist[i] << "\n";
	}
}
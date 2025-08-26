#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m;
vector<int> graph[302];
vector<int> plan;
bool visit[302];

bool bfs(int dep, int arr) {
	fill_n(visit, n + 1, false);
	queue<int> q;
	visit[dep] = true;
	q.push(dep);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == arr) return true;

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];

			if (visit[next]) continue;

			visit[next] = true;
			q.push(next);
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill_n(visit, 10, true);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int isConnected;
		for (int j = 1; j <= n; j++) {
			cin >> isConnected;
			if (i == j) continue;
			if (isConnected == 0) continue;
			graph[i].push_back(j);
		}
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		plan.push_back(num);
	}

	bool possible = false;

	for (int i = 1; i < m; i++) {
		if (!bfs(plan[i - 1], plan[i])) break; // O(n + e) -> O(600)
		
		if (i == m - 1) possible = true;
	}

	if (possible || m == 1) cout << "YES\n";
	else cout << "NO\n";
}
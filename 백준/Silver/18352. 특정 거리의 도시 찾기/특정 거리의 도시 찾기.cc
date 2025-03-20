#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n, m, k, start;
vector<int> graph[300001];
int dist[300001];
bool visit[300001];
vector<int> ans;

void bfs() {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];

			if (visit[next]) continue;

			dist[next] = dist[curr] + 1;
			q.push(next);
			visit[next] = true;
			if (dist[next] == k) ans.push_back(next);
		}
	}
}

int main() {
	cin >> n >> m >> k >> start;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}

	bfs();

	if (ans.size() == 0) {
		cout << "-1\n";
		return 0;
	}

	sort(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i << "\n";
	}

	return 0;
	
}
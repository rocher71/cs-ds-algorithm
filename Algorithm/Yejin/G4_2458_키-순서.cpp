#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<int> in[501], out[501], graph[501], inGraph[501];
bool visit[501];

void bfs(int start, bool isIn = false) {
	fill_n(visit, n + 1, false);
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int curr = q.front();

		if (curr != start && isIn) in[start].push_back(curr);
		else if (curr != start && !isIn) out[start].push_back(curr);
		q.pop();

		int goSize = isIn ? inGraph[curr].size() : graph[curr].size();
		vector<int>::iterator it = isIn ? inGraph[curr].begin() : graph[curr].begin();
		vector<int>::iterator end = isIn ? inGraph[curr].end() : graph[curr].end();
		for (; it != end; it++) {
			int next = *it;

			if (visit[next]) continue;

			q.push(next);
			visit[next] = true;
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int smaller, taller;
		cin >> smaller >> taller;
		graph[smaller].push_back(taller);
		inGraph[taller].push_back(smaller);
	}
	int cnt = 0;

	for (int i = 1; i <= n; i++) bfs(i);
	for (int i = 1; i <= n; i++) bfs(i, true);


	for (int i = 1; i <= n; i++) {
		int sum = in[i].size() + out[i].size();
		if (sum == n - 1) cnt++;
	}

	cout << cnt << "\n";



}
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 20001
using namespace std;

int tc, v, e;
vector<int> graph[MAX];
bool visit[MAX];
int colors[MAX];

bool bfs(int start) {
	queue<int> q;
	colors[start] = 1;
	q.push(start);
	visit[start] = true;
	bool firstOne = true;

	while (!q.empty()) {
		int curr = q.front();
		int currColor = colors[curr];
		q.pop();


		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			int nextColor = colors[next];

			if (nextColor == currColor) return false;
			if (nextColor != 0) continue;
			// 색이 없는 경우
			nextColor = -currColor;
			colors[next] = nextColor;
			q.push(next);
			visit[next] = true;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	while (tc--) {
		cin >> v >> e;
		fill_n(colors, v + 1, 0);
		fill_n(visit, v + 1, 0);
		for (int i = 1; i <= v; i++) graph[i].clear();

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		bool ans = false;
		for (int i = 1; i <= v; i++) {

			if (visit[i]) continue;
			else ans = bfs(i);
			if (!ans) break;
		}
		

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}

/*
떨어져있는 정점들, 다 가능한 경우
1
7 5
1 3
2 3
4 5
5 6
5 7

떨어져있는 정점들, 한쪽이 불가능한 경우
1
7 6
1 3
2 3
4 5
5 6
5 7
6 7
*/
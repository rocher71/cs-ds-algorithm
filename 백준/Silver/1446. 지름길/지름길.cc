#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int n, d;
vector<pair<int, int>> info[10001];
int dist[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		info[to].push_back({ cost, from });
	}

	for (int i = 1; i <= d; i++) {
		if (info[i].size() == 0) {
			dist[i] = dist[i - 1] + 1;
			continue;
		}

		int minCost = dist[i - 1] + 1;
		for (int j = 0; j < info[i].size(); j++) {
			minCost = min(minCost, info[i][j].first + dist[info[i][j].second]);
		}
		dist[i] = minCost;
	}

	cout << dist[d] << "\n";
}
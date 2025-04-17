#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int n, m;
vector<tuple<int, int, int>> v;
int parent[100001];

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa > pb) {
		parent[pb] = pa;
		parent[a] = pa;
		parent[b] = pa;
		return;
	}
	parent[pa] = pb;
	parent[a] = pb;
	parent[b] = pb;
}

bool isSamePar(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back(make_tuple(cost, a, b));
	}

	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) parent[i] = i;

	int cnt = 0, ans = 0, maxCost = 0;
	for (int i = 0; i < m; i++) {
		int cost, a, b;
		tie(cost, a, b) = v[i];

		if (isSamePar(a, b)) continue;

		uni(a, b);
		cnt++;
		ans += cost;
		maxCost = max(maxCost, cost);

		if (cnt == n - 1) break;
	}

	cout << ans - maxCost << "\n";
}
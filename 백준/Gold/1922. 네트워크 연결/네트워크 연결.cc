#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;

int n, m;
vector<tuple<int, int, int>> vec;
int parent[1001];

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
		vec.push_back(make_tuple(cost, a, b));
	}

	sort(vec.begin(), vec.end());
	for (int i = 1; i <= n; i++) parent[i] = i;

	int cnt = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		int cost, a, b;
		tie(cost, a, b) = vec[i];

		if (isSamePar(a, b)) continue;

		uni(a, b);
		cnt++;
		ans += cost;

		if (cnt == n - 1) break;
	}

	cout << ans << "\n";
}
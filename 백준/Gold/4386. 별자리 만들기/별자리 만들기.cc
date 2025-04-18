#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cmath>
using namespace std;

int n;
int parent[101];
vector<tuple<double, int, int>> v;
vector<pair<double, double>> locs;

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
	return;
}

bool isSamPar(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		double y, x;
		cin >> y >> x;
		locs.push_back({ y, x });
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double cost = sqrt(pow(locs[i].first - locs[j].first, 2) + pow(locs[i].second - locs[j].second, 2));
			v.push_back(make_tuple(cost, i, j));
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) parent[i] = i;

	int cnt = 0;
	double ans = 0;
	for (int i = 0; i < v.size(); i++) {
		double cost;
		int a, b;
		tie(cost, a, b) = v[i];

		if (isSamPar(a, b)) continue;

		uni(a, b);
		cnt++;
		ans += cost;

		if (cnt == n - 1) break;
	}

	cout.precision(2);
	cout << fixed << ans << "\n";
	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;

int n, m;
int parent[1001];
vector<tuple<double, int, int>> v;
vector<pair<double, double>> loc; //좌표들

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

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		loc.push_back({ a, b });
	}

	for (int i = 0; i < n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		uni(a, b);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double cost = pow(loc[i].first - loc[j].first, 2) + pow(loc[i].second - loc[j].second, 2);
			v.push_back(make_tuple(sqrt(cost), i, j));
		}
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	double ans = 0;
	for (int i = 0; i < v.size(); i++) {
		double cost;
		int a, b;
		tie(cost, a, b) = v[i];

		if (isSamePar(a, b)) continue;

		uni(a, b);
		cnt++;
		ans += cost;
		//ans += sqrt(cost * 1.0);
		//if (cnt == n - 1 - m) break;
	}

	ans *= 100;
	ans = round(ans);
	cout.precision(2);
	cout << fixed << ans / 100.0 << "\n";

}
#include<iostream>
using namespace std;

int n, m;
int parents[1000001];

int find(int a) {
	if (a == parents[a]) return a;
	return parents[a] = find(parents[a]);
}

void add(int a, int b) {
	int rootA = find(parents[a]);
	int rootB = find(parents[b]);
	parents[rootB] = rootA;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			add(a, b);
			continue;
		}
		if (find(parents[a]) == find(parents[b])) cout << "YES\n";
		else cout << "NO\n";
	}
}
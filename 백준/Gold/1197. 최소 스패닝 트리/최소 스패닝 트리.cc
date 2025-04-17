#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int v, e;
int parent[10001];
vector<tuple<int, int, int>> vec;

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
	int parA = find(a);
	int parB = find(b);

	parent[parA] = parB;
	parent[a] = parB;
	parent[b] = parB;
}

bool isSamePar(int a, int b) {
	int parA = find(a);
	int parB = find(b);
	
	if (parA == parB) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		vec.push_back(make_tuple(cost, a, b));
	}

	sort(vec.begin(), vec.end());

	for (int i = 1; i <= v; i++) parent[i] = i;

	int cnt = 0, ans = 0;
	
	for (int i = 0; i < vec.size(); i++) {
		int cost, a, b;
		tie(cost, a, b) = vec[i];

		if (isSamePar(a, b)) continue;

		uni(a, b);
		cnt++;
		ans += cost;

		if (cnt == v - 1) break;
	}

	cout << ans << "\n";

}
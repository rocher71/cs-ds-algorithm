#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}
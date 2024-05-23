#include<iostream>
#include<vector>
using namespace std;

int n;
vector<pair<int, int>> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
	}
}
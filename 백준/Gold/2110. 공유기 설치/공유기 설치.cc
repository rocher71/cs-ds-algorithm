#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<unordered_set>
using namespace std;

int n, c;
vector<int> v;

bool checkDist(int dist) {
	int cnt = 1, prev = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (cnt >= c) return true;
		if (v[i] - prev < dist) continue;
		cnt++;
		prev = v[i];
	}
	return cnt >= c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> c;
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0) continue;
		
	}
	sort(v.begin(), v.end());

	int left = 0, right = v[n-1], maxDist = INT_MIN;
	int  mid;
	while (left <= right) {
		mid = (left + right) / 2;
		bool canPlace = checkDist(mid);
		if (canPlace && maxDist < mid) {
			maxDist = mid;
		}

		if (canPlace) left = mid + 1;
		else right = mid - 1;
	}

	cout << maxDist << "\n";
}
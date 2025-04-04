#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int n, minDiff = INT_MAX;
int comb[11];
pair<int, int> arr[10];

void solve(int idx, int sour, int bitter) {
	if (idx == n && sour != -1 && bitter != -1) {
		minDiff = min(minDiff, abs(sour - bitter));
		return;
	}
	if (idx == n) return;
	solve(idx + 1, sour, bitter);

	if (sour == -1) sour = arr[idx].first;
	else sour *= arr[idx].first;
	if (bitter == -1) bitter = arr[idx].second;
	else bitter += arr[idx].second;

	solve(idx + 1, sour, bitter);
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}
	/*
	if (n == 1) {
		cout << abs(arr[0].first - arr[0].second) << "\n";
		return 0;
	}*/


	solve(0, -1, -1);

	cout << minDiff << "\n";
}
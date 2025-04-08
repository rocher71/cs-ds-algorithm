#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
using namespace std;

int n, m, costSum, ans = INT_MAX;
int mems[101], costs[101], dp[101][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> mems[i];
	for (int i = 1; i <= n; i++) {
		cin >> costs[i];
		costSum += costs[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= costSum; j++) {
			if (costs[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i-1][j- costs[i]] + mems[i]);
			else dp[i][j] = dp[i - 1][j];
			if (dp[i][j] >= m) {
				ans = min(ans, j);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int n, m, tc;
int one[20001], two[20001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> one[i];
		for (int i = 0; i < m; i++) cin >> two[i];

		sort(one, one + n);
		sort(two, two + m);

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int idx = (int)(lower_bound(two, two + m, one[i]) - two);
			cnt += idx;
		}

		cout << cnt << "\n";
		fill_n(one, n, 0);
		fill_n(two, m, 0);

	}

	
}
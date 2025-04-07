#include<iostream>
#include<algorithm>
using namespace std;

int n;
int joy[21], hp[21];
int ans[101], joys[21][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> hp[i];
	for (int i = 1; i <= n; i++) cin >> joy[i];


	for (int i = 1; i <= n; i++) {
		for (int health = 99; health >= hp[i]; health--) {
			if (ans[health] > ans[health - hp[i]] + joy[i]) continue;
			ans[health] = ans[health - hp[i]] + joy[i];
		}
	}


	cout << ans[99] << "\n";

}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arr[1000001];
vector<int> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int size = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
		//if (idx >= 0) {
		//	dp.push_back(arr[i]);
		//	continue;
		//}
		//idx = abs(idx) - 1;
		//dp[idx] = arr[i];
		
		if (idx == size) {
			dp.push_back(arr[i]);
			size++;
			continue;
		}
		//cout << idx << "\n";
		dp[idx] = arr[i];
	}

	cout << size << "\n";
	return 0;

}
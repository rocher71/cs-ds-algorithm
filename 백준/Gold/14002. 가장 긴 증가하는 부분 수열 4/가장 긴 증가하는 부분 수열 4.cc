#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int n, maxLen = 1;
int arr[1001], dp[1001];
vector<int> lis;
vector<int> nums[1001];
stack<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
			maxLen = max(maxLen, dp[i]);
		}
		if (dp[i] == 0) dp[i] = 1;
	}
	cout << maxLen << "\n";

	for (int i = n - 1; i >= 0; i--) {
		
		if (dp[i] != maxLen) continue;
		st.push(arr[i]);
		maxLen--;
		if (maxLen == 0) break;
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

}
/*
6
3 2 6 4 5 1
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n, maxLen = 1;
int arr[1000001], dp[1000001];
vector<int> lis;
stack<int> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int size = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		dp[i] = idx + 1;
		maxLen = max(maxLen, dp[i]);
		if (idx == size) {
			lis.push_back(arr[i]);
			size++;
			continue;
		}
		lis[idx] = arr[i];
	}
	//maxLen++;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] != maxLen) continue;
		st.push(arr[i]);
		maxLen--;
		//if (maxLen == 0) break;
	}



	cout << size << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}
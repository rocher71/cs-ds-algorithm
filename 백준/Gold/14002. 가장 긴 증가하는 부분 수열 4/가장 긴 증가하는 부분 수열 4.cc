#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int n, maxLen = 1;
int arr[1001], dp[1001]; //dp[i] = b : arr[i]값으로 끝나는 가장 긴 증가하는 수열의 길이
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
			if(dp[i] == 0) dp[i] = 1;
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
			maxLen = max(maxLen, dp[i]);
		}
	}
	cout << maxLen << "\n";

	// dp배열을 돌며 가장 긴 증가하는 수열의 가장 큰 값부터 순차적으로 스택에 쌓아줌
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
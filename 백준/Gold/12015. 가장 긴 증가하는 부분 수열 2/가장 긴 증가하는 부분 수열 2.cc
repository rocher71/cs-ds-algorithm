#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int arr[1000001];
vector<int> dp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int size = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
		if (size == idx) {
			dp.push_back(arr[i]);
			size++;
			continue;
		}
		
		dp[idx] = arr[i];
		/*auto idx = upper_bound(dp, dp + size, arr[i]);
		dp[*idx] = arr[i];
		if (idx != dp + size) continue;
		if (*idx == size) size++;*/
			//upper_bound(dp, dp + size, arr[i]);
		//if (idx == dp + size) 
	}


	cout << size << "\n";
}
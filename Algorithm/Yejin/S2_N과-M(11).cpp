#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[8], nums[8];

void solve(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

    // 중복 수열 조건 그대로, visit 배열만 없애면 됨
	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (prev == nums[i]) continue;
		arr[k] = nums[i];
		solve(k + 1);
		prev = nums[i];
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);
	solve(0);
}
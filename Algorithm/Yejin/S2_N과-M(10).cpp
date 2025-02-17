#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
bool visit[9];
int arr[9], nums[9];

void solve(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	int prev = -1; // 중복된 수열을 출력하지 않도록 같은 층에서 같은 값을 넣지 않게 해주는 변수
	for (int i = 0; i < n; i++) {
		if (visit[i] || (prev == nums[i]) || (k != 0 && nums[i] < arr[k-1])) continue;
		visit[i] = true;
		prev = nums[i];
		arr[k] = nums[i];
		solve(k + 1);
		visit[i] = false;
		
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);
	solve(0);
}
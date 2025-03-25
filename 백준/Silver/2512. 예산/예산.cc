#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n, limit;
vector<int> v;

int getSum(int num) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		// sort했으므로 현재 값이 num보다 크면 이 뒤에 값들은 모두 num이상임
		if (v[i] >= num) {
			sum += num * (n - i);
			return sum;
		}
		sum += v[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	cin >> limit;
	
	sort(v.begin(), v.end());

	int left = 0, right = v[n-1], mid, minDiff = INT_MAX, minDiffMid, sum = 0;
	while(left <= right) {
		mid = (left + right) / 2;
		sum = getSum(mid);
		if (limit >= sum && limit - sum < minDiff) {
			minDiff = limit - sum;
			minDiffMid = mid;
		}

		if (sum == limit) break;
		if (sum < limit) left = mid + 1;
		else if (sum > limit) right = mid - 1;
	}

	cout << minDiffMid << "\n";
}
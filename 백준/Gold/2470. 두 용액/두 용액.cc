#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int n;
vector<int> numbers;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}

	sort(numbers.begin(), numbers.end());

	int ansLeft, ansRight;
	int left = 0, right = n - 1, minSum = INT_MAX, sum;
	while (left < right) {
		sum = numbers[left] + numbers[right];
		if (abs(sum) < minSum) {
			minSum = abs(sum);
			ansLeft = left;
			ansRight = right;
		}

		if (sum == 0) break;
		if (sum < 0) left++;
		if (sum > 0) right--;
	}

	cout << numbers[ansLeft] << " " << numbers[ansRight] << "\n";
}
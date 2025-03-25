#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, tc;
vector<int> numbers;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			numbers.push_back(tmp);
		}

		sort(numbers.begin(), numbers.end());

		cin >> m;
		for (int i = 0; i < m; i++) {
			int q;
			cin >> q;
			if (binary_search(numbers.begin(), numbers.end(), q)) {
				cout << "1\n";
				continue;
			}
			cout << "0\n";
		}
		numbers.clear();
	}
}
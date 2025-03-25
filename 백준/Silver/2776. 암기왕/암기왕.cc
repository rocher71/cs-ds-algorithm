#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int tc, n, m;
unordered_set<int> s;

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
			s.insert(tmp);
		}
		cin >> m;

		for (int i = 0; i < m; i++) {
			int q;
			cin >> q;
			if (s.find(q) == s.end()) {
				cout << "0\n";
				continue;
			}
			cout << "1\n";
		}
		s.clear();
	}
	
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
vector<int> v;

bool comp(int x, int y) {
	return x > y;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), comp);
	
	int count = 0;
	for (int i : v) {
		count += k / i;
		k %= i;
	}

	cout << count;

}
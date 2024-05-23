#include<iostream>
#include<stack>
using namespace std;

int k;
stack<int> st;

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			st.pop();
			continue;
		}
		st.push(x);
	}

	int sum = 0;
	if (st.empty()) {
		cout << 0;
		return 0;
	}
	int stSize = st.size();
	for (int i = 0; i < stSize; i++) {
		sum += st.top();
		st.pop();
	}
	cout << sum << "\n";
	return 0;
}
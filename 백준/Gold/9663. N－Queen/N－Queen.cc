#include<iostream>
using namespace std;

bool visit1[15], visit2[30], visit3[30];
int n, cnt;

void queen(int idx) {
	if (idx == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit1[i] || visit2[idx + i] || visit3[idx - i + 13]) continue;
		visit1[i] = true;
		visit2[idx + i] = true;
		visit3[idx - i + 13] = true;
		queen(idx + 1);
		visit1[i] = false;
		visit2[idx + i] = false;
		visit3[idx - i + 13] = false;
	}
}

int main() {
	cin >> n;
	queen(0);
	cout << cnt << "\n";
}
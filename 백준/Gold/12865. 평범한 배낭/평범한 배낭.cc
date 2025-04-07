// 1차원 배열
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int weight[101], value[101];
int oneArr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		cin >> value[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int w = k; w >= weight[i]; w--) {
			oneArr[w] = max(oneArr[w], oneArr[w - weight[i]] + value[i]);
		}
	}


	cout << oneArr[k] << "\n";
}
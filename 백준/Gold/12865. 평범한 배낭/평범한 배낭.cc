#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int weight[101], value[101];
int arr[101][100001];

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
		for (int j = 1; j <= k; j++) {
			if (weight[i] > j) {
				arr[i][j] = arr[i - 1][j];
				continue;
			}
			// else, 넣을 수 있는 경우
			arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - weight[i]] + value[i]);
		}
	}

	cout << arr[n][k] << "\n";
}
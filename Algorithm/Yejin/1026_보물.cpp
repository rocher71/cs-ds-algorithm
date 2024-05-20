#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v1;
vector<int> v2;

bool compare(int i, int j) {
	return j < i;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v1.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v2.push_back(temp);
	}

	// 어차피 답은 합만 맞으면 되므로 정렬해도 상관없음.
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), compare);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v1[i] * v2[i];
	}

	cout << sum << "\n";

}
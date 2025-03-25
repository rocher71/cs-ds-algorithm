#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int liquidCnt;
int arr[100001];


int main() {
	cin >> liquidCnt;
	for (int i = 0; i < liquidCnt; i++) cin >> arr[i];
	
	int left = 0, right = liquidCnt-1;
	int sum, ansLeft, ansRight;
	int minDiff = INT_MAX;
	
	while (left < right) {
		sum = arr[left] + arr[right];
		if (abs(sum) < minDiff) {
			minDiff = abs(sum);
			ansLeft = left;
			ansRight = right;
		}

		if (sum == 0) break;
		if (sum < 0) left++;
		else if (sum > 0) right--;
	}

	cout << arr[ansLeft] << " " << arr[ansRight] << "\n";
}

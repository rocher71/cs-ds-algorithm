#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, ans;
int time[10001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int currTime, preCnt;
		cin >> currTime >> preCnt;

		if (preCnt == 0) {
			time[i] = currTime;
			ans = max(ans, time[i]);
			continue;
		}

		if (preCnt == 1) {
			int preNum;
			cin >> preNum;
			time[i] = time[preNum] + currTime;
			ans = max(ans, time[i]);
			continue;
		}

		// 선행 관계가 2개 이상인 경우
		vector<int> preTimes(preCnt);
		for (int j = 0; j < preCnt; j++) {
			int pre;
			cin >> pre;
			preTimes[j] = time[pre];
		}

		sort(preTimes.begin(), preTimes.end());

		time[i] = preTimes[preCnt - 1] + currTime;
		ans = max(ans, time[i]);
	}

	cout << ans << "\n";
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n;
int perm[11], population[11];
vector<int> v[11];
bool visit[11];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			if (visit[next]) continue;
			q.push(next);
			visit[next] = true;
		}
	}
}

bool checkConnection(int start, int startPerm) {
	fill_n(visit, n, false);
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < v[curr].size(); i++) {
			int next = v[curr][i];
			if (visit[next] || perm[next] != startPerm) continue; // 같은 구역 아닐시 추가 안함

			visit[next] = true;
			q.push(next);
		}
	}

	// 확인한 구역끼리 연결이 모두 되어있는지 확인
	for (int i = 0; i < n; i++) {
		if (perm[i] != startPerm)continue; // 다른 구역
		
		// 같은 구역인데 방문 안함 -> 연결x
		if (!visit[i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> population[i];

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			v[i].push_back(--b);
		}
	}

	int areaCnt = 0;
	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		areaCnt++;
		bfs(i);
	}

	if (areaCnt >= 3) {
		cout << "-1\n";
		return 0;
	}

	if (areaCnt == 2) {

	}

	int minDiff = 1000;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) perm[i] = 0;
		for (int j = n - i; j < n; j++) perm[j] = 1;
		
		do {
			//cout << "=======================================\n나눈 구역 : ";
			//for (int i = 0; i < n; i++) cout << perm[i] << " ";
			//cout << "\n";
			// 나눈 구역이 각자 연결 돼있는지 확인
			bool checkedZero = false, checkedOne = false, isZeroConnected = true, isOneConnected = true;
			for (int i = 0; i < n; i++) {
				if (checkedZero && checkedOne) break;
				if (checkedZero && perm[i] == 0) continue;
				if (checkedOne && perm[i] == 1) continue;

				// 0만 확인한 상태
				if (checkedZero) {
					isOneConnected = checkConnection(i, 1);
					checkedOne = true;
					break;
				}

				// 1만 확인한 상태 - > 0확인할 차례
				if (checkedOne) {
					isZeroConnected = checkConnection(i, 0);
					checkedZero = true;
					break;
				}

				if (perm[i] == 0) {
					isZeroConnected = checkConnection(i, 0);
					checkedZero = true;
					if (!isZeroConnected) break;
					continue;
				}

				isOneConnected = checkConnection(i, 1);
				checkedOne = true;
				if (!isOneConnected) break;
			}

			if (checkedZero && !isZeroConnected || checkedOne && !isOneConnected) {
				//cout << "이어져있지 않음!\n";
				continue;
			}

			int oneSum = 0, zeroSum = 0, diff = 0;
			for (int i = 0; i < n; i++) {
				if (perm[i] == 1) oneSum += population[i];
				else zeroSum += population[i];
			}
			//cout << "1번 인구 합 : " << oneSum << ", 0번 인구 합 : " << zeroSum << "\n";
			diff = abs(oneSum - zeroSum);
			minDiff = min(minDiff, diff);
			//cout << "최소 인구차이 :  " << minDiff << "\n";
			// 최소값 확인
		} while (next_permutation(perm, perm + n));
	}

	cout << minDiff << "\n";
}
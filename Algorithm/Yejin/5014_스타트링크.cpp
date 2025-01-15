#include<iostream>
#include<queue>
using namespace std;

int totalFloors, startFloor, toGoFloor, up, down;
bool visit[1000001];

int bfs() {
	queue<pair<int, int>> q; // {類熱, �蝦驁
	q.push({ startFloor, 0 });
	visit[startFloor] = true;

	while (!q.empty()) {
		int currFloor = q.front().first;
		int currCnt = q.front().second;
		q.pop();
		if (currFloor == toGoFloor) return currCnt;

		int upFloor = currFloor + up;
		if (upFloor <= totalFloors && !visit[upFloor]) {
			q.push({ upFloor, currCnt + 1 });
			visit[upFloor] = true;
		}
		int downFloor = currFloor - down;
		// >= 0 嬴椒!!!! 0類 橈擠!!
		if (downFloor >= 1 && !visit[downFloor]) {
			q.push({ downFloor, currCnt + 1 });
			visit[downFloor] = true;
		}

	}
	return -1;
}

int main() {
	cin >> totalFloors >> startFloor >> toGoFloor >> up >> down;

	int ans = bfs();

	if (ans == -1) {
		cout << "use the stairs\n";
		return 0;
	}

	cout << ans << "\n";
	return 0;
}
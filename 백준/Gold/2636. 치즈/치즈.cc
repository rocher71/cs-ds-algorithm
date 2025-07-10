#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
#define MAX 101
#define AIR -1
#define CHEESE 1
#define BLANK 0
using namespace std;

int row, col, cnt;
int arr[MAX][MAX], times[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q;
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

void bfsCheese(int y, int x) {
	queue<pair<int, int>> cq;
	cq.push({ y, x });
	int currTime = times[y][x];

	while (!cq.empty()) {
		int currY = cq.front().first;
		int currX = cq.front().second;
		cq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = currY + dy[i];
			int nx = currX + dx[i];

			if (ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
			if (arr[ny][nx] == AIR) continue;
			if (visit[ny][nx] && times[ny][nx] <= currTime) continue;
			cnt++;
			visit[ny][nx] = true;

			if (arr[ny][nx] == CHEESE) {
				times[ny][nx] = currTime + 1;
				q.push({ ny, nx });
				continue;
			}

			arr[ny][nx] = AIR;
			times[ny][nx] = currTime;
			cq.push({ ny, nx });
		}
	}
}

void bfs() {

	q.push({ 0, 0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;
		int currTime = times[currY][currX];
		int curr = arr[currY][currX];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = currY + dy[i];
			int nx = currX + dx[i];

			if (ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
			if (visit[ny][nx] && times[ny][nx] <= currTime) continue;
			cnt++;
			visit[ny][nx] = true;

			if (arr[ny][nx] == BLANK) arr[ny][nx] = AIR;
			
			if (arr[ny][nx] == CHEESE) {
				times[ny][nx] = currTime + 1;
				//bfsCheese(ny, nx);
			}
			else {
				times[ny][nx] = currTime;
			}
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];

			if (i == row - 1 || j == col - 1 || i == 0 || j == 0) arr[i][j] = AIR;
		}
	}

	bfs();

	int maxTime = INT_MIN;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == CHEESE) maxTime = max(maxTime, times[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == CHEESE && times[i][j] == maxTime) ans++;
		}
	}

	cout << maxTime << "\n" << ans << "\n";// << cnt << "\n";
}
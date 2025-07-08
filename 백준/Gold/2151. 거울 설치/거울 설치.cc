#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#define MAX 51
using namespace std;

/*
* 0 : 빈 칸
* -1 : 벽
* 1 : 거울 설치 가능 칸
* 2 : 문
*/


int n;
int arr[MAX][MAX], cnt[MAX][MAX][4];
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> doors;

bool isIn(int ny, int nx) {
	if (ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
	return true;
}

void bfs() {
	queue <pair<pair<int, int>, int>> q; // {{y, x}, 방향}
	
	//visit[doors[0].first][doors[0].second] = true;
	for (int i = 0; i < 4; i++) {
		int ny = doors[0].first + dy[i];
		int nx = doors[0].second + dx[i];

		if (!isIn(ny, nx) || arr[ny][nx] == -1) continue;
		q.push({ {ny, nx}, i });
		cnt[ny][nx][i] = 0;
	}

	while (!q.empty()) {
		int currY = q.front().first.first;
		int currX = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		//if (currY == doors[1].first && currX == doors[1].second) return;

		int ny = currY, nx = currX;
		if (arr[currY][currX] == 0) {
			ny += dy[dir];
			nx += dx[dir];
			if (!isIn(ny, nx) || arr[ny][nx] == -1) continue;
			cnt[ny][nx][dir] = cnt[currY][currX][dir];
			q.push({ {ny, nx}, dir });
			
			continue;
		}

		// 거울을 놓을 수 있는 경우
		ny = currY + dy[dir];
		nx = currX + dx[dir];
		if (isIn(ny, nx) && arr[ny][nx] != -1) {
			q.push({ {ny, nx}, dir });
			cnt[ny][nx][dir] = cnt[currY][currX][dir];
		}
		int newDirFrom = dir == 0 || dir == 1 ? 2 : 0;
		int newDirTo = dir == 0 || dir == 1 ? 3 : 1;

		for (int i = newDirFrom; i <= newDirTo; i++) {
			ny = currY + dy[i];
			nx = currX + dx[i];

			if (!isIn(ny, nx)
				|| cnt[ny][nx][i] <= cnt[currY][currX][dir] + 1
				|| arr[ny][nx] == -1) continue;
			
			cnt[ny][nx][i] = cnt[currY][currX][dir] + 1;
			q.push({ {ny, nx}, i });
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	//fill(&cnt[0][0], &cnt[n - 1][n], INT_MAX);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				cnt[i][j][k] = INT_MAX;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			char c = str[j];
			
			if (c == '.') continue; 
			if (c == '#') {
				doors.push_back({ i, j });
				arr[i][j] = 2;
				continue;
			}
			if (c == '*') arr[i][j] = -1;
			else if (c == '!') arr[i][j] = 1;
		}
	}

	bfs();

	int ans = INT_MAX;
	for (int i = 0; i < 4; i++) ans = min(ans, cnt[doors[1].first][doors[1].second][i]);

	cout <<  ans << "\n";
}
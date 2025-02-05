#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[20][20];
// 왼 오 위 아래 왼쪽위 오른쪽위 왼쪽아래 오른쪽아래
//int dy[8] = { 0, 0, -1, 1, -1, -1, 1, 1 },
//	dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };

int dy[4] = { 0, -1, -1, -1 },
	dx[4] = { -1, 0, -1, 1 };
bool visit[20][20];
vector<pair<int, int>> route;

bool solve(int y, int x) {
	cout << "y : " << y << ", x : " << x << "\n";
	bool isWin = false;
	int currColor = arr[y][x];

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		route.clear();
		cnt = 0;
		cout << "==========" << "\n";

		for (int j = 5; j >= 1; j--) {
			//int direction = k == 0 ? -1 : 1;
			int nextY = y + dy[i] * j * -1;
			int nextX = x + dx[i] * j * -1;

			if (nextY < 1 || nextX < 1 || nextY > 19 || nextX > 19
				|| currColor != arr[nextY][nextX]) {
				if (cnt >= 6) break;
				if (cnt == 5) break;
				cnt = 0;
				continue;
			}
			route.push_back({ nextX, nextY });
			cnt++;
			cout << nextY << ", " << nextX << "\n";
		}
		for (int j = 0; j <= 5; j++) {
			int nextY = y + dy[i] * j;
			int nextX = x + dx[i] * j;

			if (nextY < 1 || nextX < 1 || nextY > 19 || nextX > 19
				|| currColor != arr[nextY][nextX]) {
				if (cnt >= 6) break;
				if (cnt == 5) break;
				cnt = 0;
				continue;
			}
			route.push_back({ nextX, nextY });
			cnt++;
			cout << nextY << ", " << nextX << "\n";
		}
		if (cnt == 5) return true;
		if (cnt >= 6) return false;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (arr[i][j] == 0) continue;
			bool isWin = solve(i, j);
			if (!isWin) continue;
			
			sort(route.begin(), route.end());

			//세로인 경우
			if (route[0].first == route[1].first) {
				cout << arr[i][j] << "\n" << route[0].second << " " << j << "\n";
				return 0;
			}

			// 그 외 -> 가장 왼쪽
			cout << arr[i][j] << "\n" << route[0].second << " " << route[0].first << "\n";
			return 0;
		}
	}

	cout << "0\n";
}
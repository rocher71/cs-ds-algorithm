#include<iostream>
#include<queue>
#include<string>
using namespace std;

int row, col, minsikY, minsikX, ans;
int arr[51][51];
bool visit[51][51][65];
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

typedef pair<int, int> pii;

void bfs() {
	queue<pair<pii, pii>> q;
	q.push({ {minsikY, minsikX}, {0, 0} }); // y, x, 이동 횟수, 키
	visit[minsikY][minsikX][0] = true;

	while (!q.empty()) {
		int currY = q.front().first.first;
		int currX = q.front().first.second;
		int currDist = q.front().second.first;
		int currKeys = q.front().second.second;
		q.pop();

		if (arr[currY][currX] == 1) {
			ans = currDist;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = currY + dy[i];
			int nx = currX + dx[i];
			int newKeys = currKeys;

			if (ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
			if (arr[ny][nx] == -1 || visit[ny][nx][newKeys]) continue;

			//cout << currKeys << " " << arr[ny][nx] << " " << arr[ny][nx] - 'A' << " " << (currKeys & (1 < (arr[ny][nx] - 'A'))) << "\n";
			// A~F 칸인데 키가 없는 경우
			if (arr[ny][nx] >= 'A' && arr[ny][nx] <= 'F'
				&& (currKeys & (1 << (arr[ny][nx] - 'A'))) == 0) continue;

			if (arr[ny][nx] >= 'a' && arr[ny][nx] <= 'f') {
				newKeys = (currKeys | (1 << (arr[ny][nx] - 'a')));
			}

			q.push({ {ny, nx}, {currDist + 1, newKeys} });
			visit[ny][nx][newKeys] = true;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> row >> col;
	
	/*cout << 'A' - 0 << "\n";
	cout << 'A' - 0 - 'A'<< "\n";
	cout << 'F' - 0 - 'A' << "\n";
	return 0;*/

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < col; j++) {
			if (str[j] == '.') continue;
			if (str[j] == '#') {
				arr[i][j] = -1;
				continue;
			}

			if (str[j] == '0') {
				minsikY = i;
				minsikX = j;
				continue;
			}

			if (str[j] == '1') {
				arr[i][j] = 1;
				continue;
			}

			// 알파벳들
			arr[i][j] = str[j] - 0;
		}
	}

	bfs();

	if (ans == 0) cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}


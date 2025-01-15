#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int row, col, k;
int arr[101][101];
bool visit[101][101];
int dy[4] = { 0, 0, -1, 1 }, 
	dx[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> xys;
vector<int> blackSpaces;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visit[y][x] = true;
	int area = 0;

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;
		q.pop();
		area++;

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
			if (visit[nextY][nextX] || arr[nextY][nextX]) continue;

			q.push({ nextY, nextX });
			visit[nextY][nextX] = true;
		}	
	}
	blackSpaces.push_back(area);
}

int main() {
	cin >> row >> col >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		xys.push_back({ a, b });
		xys.push_back({ c, d });
	}

	for (int i = 0; i < k; i++) {
		// ÁÂÇ¥ º¯È¯
		// leftBottom (x,y) ¡æ (row - 1 - y, x)
		// rightTop (x,y) ¡æ (abs(y - row), x - 1)
		pair<int, int> leftBottom = { row - 1 - xys[2 * i].second, xys[2 * i].first };
		pair<int, int> rightTop = { abs(xys[2 * i + 1].second - row), xys[2 * i + 1].first - 1};

		for (int j = rightTop.first; j <= leftBottom.first; j++) {
			for (int k = leftBottom.second; k <= rightTop.second; k++) {
				if (arr[j][k]) continue;
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visit[i][j] || arr[i][j]) continue;
			bfs(i, j);
		}
	}
	
	sort(blackSpaces.begin(), blackSpaces.end());

	cout << blackSpaces.size() << "\n";
	for (int i : blackSpaces) cout << i << " ";
	cout << "\n";

	return 0;


}
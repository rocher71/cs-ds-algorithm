#include<iostream>
#include<string>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

int row, col, k;
int arr[1001][1001], dist[1001][1001][11];
bool visit[1001][1001][11];
int dy[4] = { 0, 0, -1, 1 },
	dx[4] = { -1, 1, 0, 0 };

void bfs() {
	queue<pair<pair<int, int>, int>> q; //y, x, breakCnt
	q.push({ {0, 0}, 0 });
	visit[0][0][0] = true;
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int currY = q.front().first.first;
		int currX = q.front().first.second;
		int breackCnt = q.front().second;
		q.pop();

		if (currY == row - 1 && currX == col - 1) return;

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
			if (visit[nextY][nextX][breackCnt]) continue;

			// º®, ÀÌ¹Ì ´Ù ºÎ¼û
			if (arr[nextY][nextX] == 1 && breackCnt >= k) continue;

			// º®, ¾ÆÁ÷ ´Ù ¾È ºÎ¼û
			if (arr[nextY][nextX] == 1 && dist[nextY][nextX][breackCnt + 1] > dist[currY][currX][breackCnt] + 1) {
				visit[nextY][nextX][breackCnt + 1] = true;
				dist[nextY][nextX][breackCnt + 1] = dist[currY][currX][breackCnt] + 1;
				q.push({ {nextY, nextX}, breackCnt + 1 });
				continue;
			}

			if (arr[nextY][nextX] == 1) continue;

			// º® ¾Æ´Ô
			if (dist[nextY][nextX][breackCnt] <= dist[currY][currX][breackCnt] + 1) continue;
			dist[nextY][nextX][breackCnt] = dist[currY][currX][breackCnt] + 1;
			q.push({ { nextY, nextX }, breackCnt });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> row >> col >> k;
	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	fill(&dist[0][0][0], &dist[row][col - 1][k], INT_MAX);

	bfs();

	int minDist = INT_MAX;
	for (int i = 0; i <= k; i++) minDist = min(minDist, dist[row - 1][col - 1][i]);

	if (minDist == INT_MAX) {
		cout << "-1\n";
		return 0;
	}

	cout << minDist << "\n";
	return 0;

}
#include<iostream>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int row, col;
int arr[1001][1001];
int dist[1001][1001][2];
bool visit[1001][1001][2];
int dy[4] = { 0, 0, -1, 1 },
		dx[4] = { -1,1, 0, 0 };

typedef struct Loc {
	int y, x, breakCnt;
};


void bfs() {
	queue<Loc> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	visit[0][0][0] = true;

	while (!q.empty()) {
		int currY = q.front().y;
		int currX = q.front().x;
		int currBreakCnt = q.front().breakCnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];
			if (visit[nextY][nextX][currBreakCnt]) continue;

			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;

			// 현재 벽, 이미 부숨
			if (arr[nextY][nextX] == 1 && currBreakCnt == 1) continue;

			// 현재 벽, 아직 안 부숨
			if(arr[nextY][nextX] == 1 && currBreakCnt == 0 && dist[nextY][nextX][1] > dist[currY][currX][0] + 1){
				q.push({ nextY, nextX, 1 });
				dist[nextY][nextX][1] = dist[currY][currX][0] + 1;
				visit[nextY][nextX][1] = true;
				continue;
			}

			if (arr[nextY][nextX]) continue;

			if (dist[nextY][nextX][currBreakCnt] <= dist[currY][currX][currBreakCnt]) continue;

			// 현재 벽 아님
			q.push({ nextY, nextX, currBreakCnt });
			dist[nextY][nextX][currBreakCnt] = dist[currY][currX][currBreakCnt] + 1;
			visit[nextY][nextX][currBreakCnt] = true;

		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	fill(&dist[0][0][0], &dist[row][col-1][1], INT_MAX);
	bfs();

	int minDist = min(dist[row - 1][col - 1][0], dist[row - 1][col - 1][1]);
	if ( minDist == INT_MAX) {
		cout << "-1\n";
		return 0;
	}

	cout << minDist << "\n";
}
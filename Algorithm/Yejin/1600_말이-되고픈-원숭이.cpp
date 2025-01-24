#include<iostream>
#include<queue>
using namespace std;

int row, col, k;
int arr[201][201], cost[201][201][31];
bool visit[201][201][31];
int dy[12] = { -2, -2, -1, -1, 1, 1, 2, 2, 0, 0, 1, -1 },
	dx[12] = { -1, 1, -2, 2, 2, -2, -1, 1, -1, 1, 0, 0 };


int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	visit[0][0][0] = true;

	while (!q.empty()) {
		int currY = q.front().first.first;
		int currX = q.front().first.second;
		int horseMoveCount = q.front().second;
		q.pop();

		if (currY == row - 1 && currX == col - 1) return cost[row - 1][col - 1][horseMoveCount];

		
		// 말 움직임
		if (horseMoveCount < k) {
			for (int i = 0; i < 8; i++) {
				int nextY = currY + dy[i];
				int nextX = currX + dx[i];

				if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue; //범위 초과
				if (visit[nextY][nextX][horseMoveCount + 1]) continue; //이미 방문
				if (arr[nextY][nextX]) continue; // 벽

				q.push({ {nextY, nextX}, horseMoveCount + 1 });
				visit[nextY][nextX][horseMoveCount + 1] = true;
				cost[nextY][nextX][horseMoveCount + 1] = cost[currY][currX][horseMoveCount] + 1;
				
			}
		}

		// 상하좌우
		for (int i = 8; i < 12; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue; //범위 초과
			if (visit[nextY][nextX][horseMoveCount]) continue; //이미 방문
			if (arr[nextY][nextX]) continue; // 벽

			q.push({ {nextY, nextX}, horseMoveCount });
			visit[nextY][nextX][horseMoveCount] = true;
			cost[nextY][nextX][horseMoveCount] = cost[currY][currX][horseMoveCount] + 1;

		}
		

		/* 
		// 말움직임 & 상하좌우 한번에 도는 코드, 실행 잘 됨, 위에랑 12ms 차이
		//cout << "(" << currY << ", " << currX << ")" << "\n";
		for (int i = (horseMoveCount < k ? 0 : 8); i < 12; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];
			int newMoveCnt = i <= 7 ? horseMoveCount + 1 : horseMoveCount;

			if (arr[nextY][nextX]) continue;
			if (visit[nextY][nextX][newMoveCnt]) continue;
			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;

			visit[nextY][nextX][newMoveCnt] = true;
			cost[nextY][nextX][newMoveCnt] = cost[currY][currX][horseMoveCount] + 1;
			q.push({ {nextY, nextX}, newMoveCnt });
			
		} */
		
	}

	return -1;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> k >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) cin >> arr[i][j];
	}

	cout << bfs() << "\n";
	return 0;
}
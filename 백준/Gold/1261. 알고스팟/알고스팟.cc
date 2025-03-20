#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int row, col;
int arr[101][101], breakCnt[102][102];
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	breakCnt[0][0] = arr[0][0];

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;

			int nextCnt = breakCnt[currY][currX] + (arr[nextY][nextX] ? 1 : 0);
			// 이미 더 적은 숫자가 적혀있는 경우
			if (breakCnt[nextY][nextX] <= nextCnt) continue;

			q.push({ nextY, nextX });
			breakCnt[nextY][nextX] = nextCnt;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> col >> row;
	fill(&breakCnt[0][0], &breakCnt[row - 1][col], INT_MAX);
	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	
	bfs();

	cout << breakCnt[row - 1][col- 1] << "\n";
}
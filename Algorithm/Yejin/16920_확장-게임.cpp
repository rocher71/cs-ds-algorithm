/*
	���� 16920 Ȯ�� ����
	��ũ : https://www.acmicpc.net/problem/16920
*/

#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

// playerCnt : �÷��̾� ��, totalCnt : ���� ������ ���� ���� �� ��ҵ��� ��
int row, col, playerCnt, isEnd;
int arr[1001][1001];
int cnt[1001], dist[1001];
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };
bool visit[1001][1001];

void bfs(int player) {
	queue<pair<pair<int, int>, int>> q; // y, x, �̵�Ƚ��

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] != player || visit[i][j]) continue;
			q.push({ { i, j }, 0 });
		}
	}

	// cntBfs : player�� Ȯ�� ���θ� Ȯ���ϴ� ����
	int cntBfs = 0;
	while (!q.empty()) {
		int currY = q.front().first.first;
		int currX = q.front().first.second;
		int moveCnt = q.front().second;
		q.pop();
		visit[currY][currX] = true; // Ȯ���� ����� �� Ž����(�ϰ� ��) �ָ� visit true

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
			if (arr[nextY][nextX] != 0 || visit[nextY][nextX]) continue;

			cnt[player]++;
			arr[nextY][nextX] = player;
			cntBfs++;

			if (moveCnt + 1 >= dist[player]) continue;
			q.push({ {nextY, nextX}, moveCnt + 1 });
			//visit[nextY][nextX] = true; ���ڵ� �ּ�ó�� ���ص� �±���
		}
	}
	if (cntBfs == 0) isEnd++;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> row >> col >> playerCnt;

	for (int i = 1; i <= playerCnt; i++) cin >> dist[i];

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < col; j++) {
			int c = str[j];
			if (c == '.') continue;
			if (c == '#') {
				arr[i][j] = -1;
				continue;
			}
			arr[i][j] = c - '0';
			cnt[arr[i][j]]++;
		}
	}

	/*
		�������� : ��� player�� ���̻� Ȯ���� �� ���� ��.
		���� player �Ѹ��� Ȯ�� ���� ���Ҷ�����
		isEnd �� +1 ������ �� player�� �� �������� ����.

		#, player1, ... , players �� ������ ������ row*col �� ���Ͽ� �����ϸ� �ȵ�.
		. . . . 1
		. # # # .
		. # . # .
		. # . # .
		. # # # .
		2 . . . .
		���Ͱ��� �� �����̴��� ������ �� ���� hidden test case�� ������!
	*/
	while (isEnd != playerCnt) {
		isEnd = 0;
		for (int i = 1; i <= playerCnt; i++) {
			bfs(i);
			if (isEnd == playerCnt) break;
		}
	}


	for (int i = 1; i <= playerCnt; i++) cout << cnt[i] << " ";
	cout << "\n";

	return 0;

}
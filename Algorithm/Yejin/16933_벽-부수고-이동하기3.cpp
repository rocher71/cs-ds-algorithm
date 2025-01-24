#include<iostream>
#include<queue>
#include<climits>
#include<string>
#define day 1
#define night 0
using namespace std;

int row, col, k;
int arr[1001][1001];
//, cost[1001][1001][11][2];
bool visit[1001][1001][11][2];
int dy[4] = { 0, 0, -1, 1 },
dx[4] = { -1, 1, 0, 0 };

typedef struct Loc {
	//int y, x, breackCnt, isDay;
	int y, x, breackCnt, distance;
};

int bfs() {
	queue<Loc> q;
	q.push({ 0, 0, 0, 1 });
	//cost[0][0][0][1] = 1;
	visit[0][0][0][1] = true;

	while (!q.empty()) {
		int currY = q.front().y;
		int currX = q.front().x;
		int breakCnt = q.front().breackCnt;
		int time = q.front().distance % 2;
		int nextCost = q.front().distance + 1;
		q.pop();

		//cout << currY << " " << currX << " " << breakCnt << " " << time << " " << cost[currY][currX][breakCnt][time] << "\n";

		if (currY == row - 1 && currX == col - 1) return nextCost - 1;

		int nextTime = !time;

		//�����ֱ� (���ϼ� ����)
		if (!visit[currY][currX][breakCnt][nextTime]) {
			visit[currY][currX][breakCnt][nextTime] = true;
			//cost[currY][currX][breakCnt][nextTime] = nextCost;
			q.push({ currY, currX, breakCnt, nextCost });
		}

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;

			// ��, �̹� k��ŭ �μ� or ��
			if (arr[nextY][nextX] && (breakCnt == k || time == night)) continue;

			// ��, �̹� �湮�� ���̸� pass
			if (arr[nextY][nextX] && visit[nextY][nextX][breakCnt + 1][nextTime]) continue;

			// ��, ���� breack cnt ����, �湮 ���� ��, ���� �� -> �� ���� ����
			if (arr[nextY][nextX]) {
				visit[nextY][nextX][breakCnt + 1][nextTime] = true;
				//cost[nextY][nextX][breakCnt + 1][nextTime] = nextCost;
				q.push({ nextY, nextX, breakCnt + 1, nextCost });
				continue;
			}

			// �� �ƴ�, �̹� �湮�� ���̸� pass
			if (visit[nextY][nextX][breakCnt][nextTime]) continue;

			// �� �ƴ�, �湮 ���� �� -> �� �ȱ��� ����
			visit[nextY][nextX][breakCnt][nextTime] = true;
			//cost[nextY][nextX][breakCnt][nextTime] = nextCost;
			q.push({ nextY, nextX, breakCnt, nextCost });

		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
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

	cout << bfs() << "\n";

	
}
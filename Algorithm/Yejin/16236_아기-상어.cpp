#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//2559

int n, sharkSize = 2, currEatCnt, sharkY, sharkX, timeCnt;
int arr[21][21];
bool visit[21][21];
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

int bfsFromChicken(int toY, int toX) {
	queue<pair<pair<int, int>, int>> q;
	fill(&visit[0][0], &visit[n - 1][n], 0);
	q.push({ { sharkY, sharkX }, 0});
	visit[sharkY][sharkX] = 0;

	while (!q.empty()) {
		int currY = q.front().first.first;
		int currX = q.front().first.second;
		int currDist = q.front().second;
		q.pop();

		if (currY == toY && currX == toX) {
			return currDist;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];
			
			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
			if (arr[nextY][nextX] > sharkSize || visit[nextY][nextX]) continue;

			q.push({ { nextY, nextX }, currDist + 1 });
			visit[nextY][nextX] = true;
		}
	}

	return 1000;
}

void eatFish(int toY, int toX, int dist) {
	// 1. ��� ��ġ ����
	arr[sharkY][sharkX] = 0;
	arr[toY][toX] = 9;
	sharkY = toY;
	sharkX = toX;

	// 2. ���� �� �Ÿ���ŭ �����ֱ�
	timeCnt += dist;

	// 3. ��� size ����
	if (++currEatCnt == sharkSize) {
		currEatCnt = 0;
		sharkSize++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 9) continue;
			//����� ���
			sharkY = i;
			sharkX = j;
		}
	}

	while (true) {
		int minDistY = 0, minDistX = 0, minDist = 1000;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// �� ĭ, �� �ִ� ĭ, ���� �� ū ������ �ִ� ĭ�� pass
				if (arr[i][j] == 0 || arr[i][j] == 9 || arr[i][j] >= sharkSize) continue;

				int currDist = bfsFromChicken(i, j);

				if (currDist > minDist) continue;

				if (currDist == minDist) {
					if (minDistY < i) continue; // ���� �Ÿ�, min�� y���� ���� ��
					if (minDistY == i && minDistX < j) continue; //���� �Ÿ�, y���� ���� min�� x ���� �� ���� ��

					//���� ���� ������ i �� �� ����
					minDistY = i;
					minDistX = j;
					continue;
				}

				// currDist < minDist
				minDistY = i;
				minDistX = j;
				minDist = currDist;
			}
		}
		if (minDist == 1000) break;

		eatFish(minDistY, minDistX, minDist);
	}

	cout << timeCnt << "\n";
}
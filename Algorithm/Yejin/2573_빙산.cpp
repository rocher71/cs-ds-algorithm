#include<iostream>
#include<queue>
using namespace std;

int row, col, time, heightSum;
pair<int, int> arr[301][301]; // arr[i][j] = {a, b} : i, j��ǥ ������ ���̴� a, �ֺ� �ٴٰ����� b
bool visit[301][301];
int dy[4] = { 0, 0, -1, 1 },
	dx[4] = { -1, 1, 0, 0 };
/*
	heightSum : ��ü ������ ���� ���. ��� ���� ��� while�� Ż���� ���� �ʿ�
*/

// BFS�� ��� ���� ����
void countChunk(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visit[y][x] = true;

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];
			
			if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
			if (visit[nextY][nextX] || arr[nextY][nextX].first == 0) continue;

			q.push({ nextY, nextX });
			visit[nextY][nextX] = true;
		}
	}
}

// �� ���� ��ǥ �� �ֺ� �ٴ� ����
// �̶� ���� ������ �и��ؾ��� (��� �� ������ �ٷ��ϸ� ���� ���ϰ� ������ ����)
void countOcean() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j].first == 0) continue; // �ٴٴ� �� �ʿ� ����

			int cnt = 0;
			// �Ʒ� �� �� �� ������ �ٴ����� Ȯ��
			if (i - 1 >= 0 && arr[i - 1][j].first == 0) cnt++;
			if (i + 1 < row && arr[i + 1][j].first == 0) cnt++;
			if (j - 1 >= 0 && arr[i][j-1].first == 0) cnt++;
			if (j + 1 < col && arr[i][j+1].first == 0) cnt++;

			// �ֺ� �ٴ� ���� ����
			arr[i][j].second = cnt;
		}
	}
}

// ������ ���� ����
void renewHeight() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			heightSum += arr[i][j].first;
			//�ٴ� �̰ų� �ֺ� �ٴ� ������ 0�̸� pass
			if (arr[i][j].first == 0 || arr[i][j].second == 0) continue;
			
			// arr[i][j].first -= arr[i][j].first; ó���� �̷��� �׳� ���µ�
			// ������ ���� ��ü ���̼� ��꿡 ������ ����
			arr[i][j].first = arr[i][j].first - arr[i][j].second < 0 ? 0 : arr[i][j].first -= arr[i][j].second;
			//arr[i][j].second = 0; ��� ����
			
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int a;
			cin >> a;
			arr[i][j] = { a, 0 }; // ���� a, �ֺ� �ٴ� ���� �𸣹Ƿ� 0
		}
	}

	// ó������ �� ��� �̻��� ��� �ľ�
	int chunk = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visit[i][j] || arr[i][j].first == 0) continue;
			countChunk(i, j);
			chunk++;
		}
	}
	if (chunk >= 2) {
		cout << "0\n";
		return 0;
	}

	//cout << "===========================================\n";

	// ����� 2�� �̸��ΰ�� ��� �ݺ�
	while (chunk < 2) {
		fill(&visit[0][0], &visit[301][301], false);

		time++;
		chunk = 0, heightSum = 0;
		countOcean(); // �� ���Ϻ� �ֺ� �ٴټ� ��
		renewHeight(); // ���̰��� (���� ����-�ֺ� �ٴټ�)

		// ��� �� ��
		for (int i = 0; i < row; i++ ) {
			for (int j = 0; j < col; j++) {
				if (visit[i][j] || arr[i][j].first == 0) continue;
				countChunk(i, j);
				chunk++;
			}
		}
		// cout << "time : " << time << ", chunk : " << chunk << "\n";
		// cout << "===========================================\n";

		if (chunk >= 2 || heightSum <= 0) break;
	}

	if (chunk >= 2) {
		cout << time << "\n";
		return 0;
	}

	cout << "0\n";

	return 0;


}

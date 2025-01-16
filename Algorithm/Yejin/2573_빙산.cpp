#include<iostream>
#include<queue>
using namespace std;

int row, col, time, heightSum;
pair<int, int> arr[301][301]; // arr[i][j] = {a, b} : i, j좌표 빙하의 높이는 a, 주변 바다개수는 b
bool visit[301][301];
int dy[4] = { 0, 0, -1, 1 },
	dx[4] = { -1, 1, 0, 0 };
/*
	heightSum : 전체 빙하의 높이 계산. 모두 녹은 경우 while문 탈출을 위해 필요
*/

// BFS로 덩어리 개수 세기
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

// 각 빙하 좌표 당 주변 바다 세기
// 이때 계산과 갱신을 분리해야함 (계산 후 갱신을 바로하면 옆의 빙하가 영향을 받음)
void countOcean() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j].first == 0) continue; // 바다는 셀 필요 없음

			int cnt = 0;
			// 아래 위 좌 우 순으로 바다인지 확인
			if (i - 1 >= 0 && arr[i - 1][j].first == 0) cnt++;
			if (i + 1 < row && arr[i + 1][j].first == 0) cnt++;
			if (j - 1 >= 0 && arr[i][j-1].first == 0) cnt++;
			if (j + 1 < col && arr[i][j+1].first == 0) cnt++;

			// 주변 바다 개수 저장
			arr[i][j].second = cnt;
		}
	}
}

// 빙하의 높이 갱신
void renewHeight() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			heightSum += arr[i][j].first;
			//바다 이거나 주변 바다 개수가 0이면 pass
			if (arr[i][j].first == 0 || arr[i][j].second == 0) continue;
			
			// arr[i][j].first -= arr[i][j].first; 처음에 이렇게 그냥 뺐는데
			// 음수로 가면 전체 높이수 계산에 착오가 생김
			arr[i][j].first = arr[i][j].first - arr[i][j].second < 0 ? 0 : arr[i][j].first -= arr[i][j].second;
			//arr[i][j].second = 0; 없어도 맞음
			
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int a;
			cin >> a;
			arr[i][j] = { a, 0 }; // 높이 a, 주변 바다 개수 모르므로 0
		}
	}

	// 처음부터 두 덩어리 이상인 경우 파악
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

	// 덩어리가 2개 미만인경우 계속 반복
	while (chunk < 2) {
		fill(&visit[0][0], &visit[301][301], false);

		time++;
		chunk = 0, heightSum = 0;
		countOcean(); // 각 빙하별 주변 바다수 셈
		renewHeight(); // 높이갱신 (빙하 높이-주변 바다수)

		// 덩어리 수 셈
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

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int n, maxHeight, minHeight;
int arr[101][101];
bool visit[101][101];
vector<int> areaCnt;
int dy[4] = { 0, 0, -1, 1 },
	dx[4] = { -1, 1, 0, 0 };

void bfs(int y, int x, int sinkHeight) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visit[y][x] = true;

	while (!q.empty()) {
		int currY = q.front().first;
		int currX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = currY + dy[i];
			int nextX = currX + dx[i];

			if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
			if (visit[nextY][nextX] || arr[nextY][nextX] <= sinkHeight) continue;
			
			q.push({ nextY, nextX });
			visit[nextY][nextX] = true;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			maxHeight = max(maxHeight, arr[i][j]);
			minHeight = min(minHeight, arr[i][j]);
		}
	}

	for (int i = minHeight; i <= maxHeight - 1; i++) {
		// height 별로 bfs 돌기 위해 visit 배열 초기화
		fill(&visit[0][0], &visit[100][101], false);
		int area = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (visit[j][k] || arr[j][k] <= i) continue;
				bfs(j, k, i);
				area++;
			}
		}
		areaCnt.push_back(area);
	}
	
	sort(areaCnt.begin(), areaCnt.end());
	cout << areaCnt[areaCnt.size() - 1] << "\n";
}
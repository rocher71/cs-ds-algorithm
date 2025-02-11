#include<iostream>	
#include<queue>
#include<vector>
using namespace std;

int n, m, cloudCnt;
int water[51][51];
bool isCloud[51][51];
vector<pair<int, int>> moveInfo;
vector<pair<int, int>> clouds;
int directions[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1,1}, {1, 0}, {1, -1} };
int dy[4] = { -1, -1, 1, 1 }, dx[4] = { -1, 1, -1, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> water[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		moveInfo.push_back({ --a, b });
	}

	// 초기 구름 셋팅
	clouds.push_back({ n - 1, 0 });
	clouds.push_back({ n - 1, 1 });
	clouds.push_back({ n - 2, 0 });
	clouds.push_back({ n - 2, 1 });
	isCloud[n - 1][0] = true;
	isCloud[n - 1][1] = true;
	isCloud[n - 2][0] = true;
	isCloud[n - 2][1] = true;
	cloudCnt = 4;

	for (int tc = 0; tc < m; tc++) {
		int d = moveInfo[tc].first;
		int strength = moveInfo[tc].second;
		vector<pair<int, int>> movedClouds;

		// 구름 이동
		for (int i = 0; i < cloudCnt; i++) {
			int currY = clouds[i].first;
			int currX = clouds[i].second;
			int newY = currY, newX = currX;

			for (int i = 0; i < strength; i++) {
				newY += directions[d][0];
				newX += directions[d][1];
				if (newY < 0) newY = n - 1;
				else if (newY >= n) newY = 0;

				if (newX < 0) newX = n - 1;
				else if (newX >= n) newX = 0;
			}

			water[newY][newX] += 1;
			movedClouds.push_back({ newY, newX });
		}

		fill(&isCloud[0][0], &isCloud[n - 1][n], false);

		for (pair<int, int> cloud : movedClouds) {
			int cntDiag = 0;
			isCloud[cloud.first][cloud.second] = true;
			for (int k = 0; k < 4; k++) {
				int checkY = cloud.first + dy[k];
				int checkX = cloud.second + dx[k];

				if (checkY < 0 || checkX < 0 || checkY >= n || checkX >= n)  continue;
				if (water[checkY][checkX] == 0) continue;

				cntDiag++;
			}
			water[cloud.first][cloud.second] += cntDiag;
		}
		clouds.clear();

		// 새로운 구름 형성
		cloudCnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isCloud[i][j]) {
					isCloud[i][j] = false;
					continue;
				}
				if (water[i][j] < 2) continue;

				isCloud[i][j] = true;
				clouds.push_back({ i, j });
				water[i][j] -= 2;
				cloudCnt++;
			}
		}
		cout << tc << "\n";
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) ans += water[i][j];
	}

	cout << ans << "\n";


}
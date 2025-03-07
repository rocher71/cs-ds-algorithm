#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int row, col, maxDist;
int arr[21][21];
bool boxVisit[21][21], alphaVisit[27];
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

void dfs(int y, int x, int dist) {
	maxDist = max(maxDist, dist);

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
		if (boxVisit[nextY][nextX] || alphaVisit[arr[nextY][nextX]]) continue;

		boxVisit[nextY][nextX] = true;
		alphaVisit[arr[nextY][nextX]] = true;

		dfs(nextY, nextX, dist + 1);

		boxVisit[nextY][nextX] = false;
		alphaVisit[arr[nextY][nextX]] = false;
	}
}

int main() {
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < col; j++) {
			arr[i][j] = str[j] - 'A';
		}
	}
	
	alphaVisit[arr[0][0]] = true;
	boxVisit[0][0] = true;
	dfs(0, 0, 1);
	cout << maxDist << "\n";
}
#include<iostream>
#include<queue>
using namespace std;


typedef struct Location {
	int z, y, x;
};

int height, row, col;
int arr[31][31][31], time[31][31][31];
int dz[6] = { 0, 0, 0, 0, -1, 1 },
	dy[6] = { 0, 0, -1, 1, 0, 0 },
	dx[6] = { -1, 1, 0, 0, 0, 0 };
bool visit[31][31][31];
Location depart, dest;

void bfs() {
	queue<Location> q;
	q.push(depart);
	visit[depart.z][depart.y][depart.x] = true;
	time[depart.z][depart.y][depart.x] = 0;

	while (!q.empty()) {
		int currZ = q.front().z;
		int currY = q.front().y;
		int currX = q.front().x;
		q.pop();

		if (currZ == dest.z && currY == dest.y && currX == dest.x) return;
		
		for (int i = 0; i < 6; i++) {
			//int nextZ = currZ + dz[i];
			//int nextY = currY + dy[i];
			//int nextX = currX + dx[i];
			Location next = { currZ + dz[i], currY + dy[i], currX + dx[i] };
			
			if (next.z < 0 || next.y < 0 || next.x < 0 || next.z >= height || next.y >= row || next.x >= col) continue;
			if (visit[next.z][next.y][next.x] || arr[next.z][next.y][next.x] == 0) continue;
			
			q.push(next);
			visit[next.z][next.y][next.x] = true;
			time[next.z][next.y][next.x] = time[currZ][currY][currX] + 1;
		}

	}
}

int main() {
	cin >> height >> row >> col;
	while (height != 0 && row != 0 && col != 0) {
		fill(&arr[0][0][0], &arr[height][row][col], 0);
		fill(&time[0][0][0], &time[height][row][col], 0);
		fill(&visit[0][0][0], &visit[height][row][col], false);

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < row; j++) {
				for (int k = 0; k < col; k++) {
					char c;
					cin >> c;
					if (c == '#') continue;
					if (c == '.') {
						arr[i][j][k] = 1;
						continue;
					}
					if (c == 'S') {
						depart = { i, j, k };
						arr[i][j][k] = 1;
						continue;
					}
					// c == 'E'
					dest = { i, j, k };
					arr[i][j][k] = 1;
					time[i][j][k] = -1;
				}
			}
		}

		bfs();

		if (time[dest.z][dest.y][dest.x] == -1) {
			cout << "Trapped!\n";
			cin >> height >> row >> col;

			continue;
		}

		cout << "Escaped in " << time[dest.z][dest.y][dest.x] << " minute(s).\n";
		cin >> height >> row >> col;

		continue;
	}

	return 0;
}

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define n 101
using namespace std;

int row, col;
int arr[n][n], visit[n][n], zoneNum[n][n];
bool isZoneIn[n * n];
queue<pair<int, int>> cheeseQ;
int dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };

void bfs(int y, int x, int zone, int time) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visit[y][x] = time;
    zoneNum[y][x] = zone;
    bool isIn = true;

    while (!q.empty()) {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = currY + dy[i];
            int nx = currX + dx[i];

            // 영역 탐색 중 테두리 닿으면 밖
            if (ny < 0 || nx < 0 || ny >= row || nx >= col) {
                isIn = false;
                continue;
            }
            if (visit[ny][nx] == time || arr[ny][nx] == 1) continue;

            visit[ny][nx] = time;
            zoneNum[ny][nx] = zone;
            q.push({ ny, nx });
        }
    }

    isZoneIn[zone] = isIn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) cheeseQ.push({ i, j });
        }
    }

    int time = 1;
    while (!cheeseQ.empty()) {
        int zoneCnt = 1;
        int cheeseCnt = cheeseQ.size();
        for (int idx = 0; idx < cheeseCnt; idx++) {
            int y = cheeseQ.front().first;
            int x = cheeseQ.front().second;
            cheeseQ.pop();

            // 전 타임에 공기 접촉면이 2곳 이상이면 이번 타임에 사라짐
            //if (airCnts[y][x] >= 2) continue;
            int airCnt = 0;
            // 상하좌우 공기인지 확인
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                // 옆이 치즈면 continue
                if (arr[ny][nx] == 1) continue;

                // 이번 타임에 방문한 적 없는 곳이라면 영역 탐색
                if (visit[ny][nx] != time) {
                    bfs(ny, nx, zoneCnt, time);
                    zoneCnt++;
                }
                
                // 현재 칸이 치즈 내부라면 continue
                if (isZoneIn[zoneNum[ny][nx]]) continue;

                airCnt++;
                if (airCnt >= 2) break;
            }

            // 이번 타임 탐색 결과 공기면 2개 이상이면 q에 다시 넣지 않음
            if (airCnt >= 2) arr[y][x] = 0;
            else cheeseQ.push({ y, x });
        }

        /*
        cout << "\ntime : " << time << "\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }*/

        time++;
    }

    cout << time - 1 << "\n";
}

/*
8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0


*/
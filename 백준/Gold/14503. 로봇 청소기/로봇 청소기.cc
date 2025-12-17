#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 51
using namespace std;

int row, col, startY, startX, startDir;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}; // 위 오른쪽 아래 왼쪽
int arr[MAX][MAX];
bool isCleaned[MAX][MAX];

int getBackDirection(int dir){
    if(dir == 0) return 2;
    if(dir == 2) return 0;
    if(dir == 1) return 3;
    return 1;
}

int getCounterClockwiseDirection(int dir){
    if(dir == 0) return 3;
    if(dir == 1) return 0;
    if(dir == 2) return 1;
    return 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    cin >> startY >> startX >> startDir;
    for(int i = 0 ;i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
            if(arr[i][j]) isCleaned[i][j] = 1;
        }
    }

    bool canMove = true;
    int currY = startY, currX = startX, currDir = startDir, cleanCnt = 0;
    while(canMove){
//        cout << currY << " " << currX << " " << currDir << "\n";
//        for(int i = 0 ;i < row; i++){
//            for(int j = 0; j < col; j++){
//                cout << isCleaned[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        if(!isCleaned[currY][currX]){
            isCleaned[currY][currX] = true;
            cleanCnt++;
        }

        bool dirtyAdjExists = false;
        int dirtyAdjDir = -1;
        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            // 범위 체크, 벽이거나 이미 청소된 칸은 continue
            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
            if(arr[nextY][nextX] || isCleaned[nextY][nextX]) continue;

            dirtyAdjExists = true;
            dirtyAdjDir = i;
            break;
        }


        // 주변 4 칸 중 청소되지 않은 칸이 있으면 해당 칸으로 방향을 전환하고 전진 -> x
        // 청소되지 않은 칸이 있으면 반시계 90도 회전
        if(dirtyAdjExists){
//            currY += dy[dirtyAdjDir];
//            currX += dx[dirtyAdjDir];
//            currDir = dirtyAdjDir;
//            continue;
            int nextDir = getCounterClockwiseDirection(currDir);
            int nextY = currY + dy[nextDir];
            int nextX = currX + dx[nextDir];
//            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col){
//                canMove = false;
//                break;
//            }
            if(isCleaned[nextY][nextX]){
                currDir = nextDir;
                continue;
            }

            currY = nextY;
            currX = nextX;
            currDir = nextDir;
            continue;
        }

        // 청소되지 않은 칸이 없다면 후진, 후진 할 수 없으면 동작 끝
        int backDir = getBackDirection(currDir);
        int nextY = currY + dy[backDir];
        int nextX = currX + dx[backDir];

        // 범위 밖이거나 벽인 경우 동작 끝
        if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col || arr[nextY][nextX]){
            canMove = false;
            break;
        }

        currY = nextY;
        currX = nextX;

    }

    cout << cleanCnt << "\n";
}

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#define APPLE 2
#define SNAKE 1
#define LEFT 1
#define RIGHT 2
using namespace std;

int n, appleCnt, dirCnt,currDir = 1, currTime = 0;
int arr[101][101];
queue<pair<int, int>> cmd;
deque<pair<int, int>> snakeLocs;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int turnLeft(){
    if(currDir == 0) return 3;
    if(currDir == 1) return 0;
    if(currDir == 2) return 1;
    return 2;
}

int turnRight(){
    if(currDir == 0) return 1;
    if(currDir == 1) return 2;
    if(currDir == 2) return 3;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cmdCnt;

    cin >> n >> appleCnt;
    for(int i = 0; i< appleCnt; i++){
        int y, x;
        cin >> y >> x;
        arr[y - 1][x - 1] = APPLE;
    }
    cin >> cmdCnt;
    for(int i = 0; i< cmdCnt; i++){
        int sec;
        char dir;
        cin >> sec >> dir;
        if(dir == 'L') cmd.push({sec, LEFT});
        else cmd.push({sec, RIGHT});
    }

    arr[0][0] = SNAKE;
    snakeLocs.push_front({0, 0});
    bool canGo = true;
    while(canGo){
        currTime++;
        int nextY = snakeLocs.front().first + dy[currDir];
        int nextX = snakeLocs.front().second + dx[currDir];

//        cout << "\n" << currTime - 1 << "\n";
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++){
//                cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }

        // 벽이나 몸에 부딪히면 끝
        if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n || arr[nextY][nextX] == SNAKE){
            canGo = false;
            break;
        }

        bool haveToChange = cmd.front().first == currTime ? true : false;
        bool isApple = arr[nextY][nextX] == APPLE ? true : false;
        if(isApple) arr[nextY][nextX] = 0;

        // 우선 머리는 한 칸 전진
        arr[nextY][nextX] = SNAKE;
        snakeLocs.push_front({nextY, nextX});

        // 다음 칸이 사과가 아니면 꼬리 전진
        if(!isApple){
            arr[snakeLocs.back().first][snakeLocs.back().second] = 0;
            snakeLocs.pop_back();
        }

        // 움직일 필요가 없다면 continue;
        if(!haveToChange) continue;

        // 방향 전환
        if(cmd.front().second == LEFT) currDir = turnLeft();
        else currDir = turnRight();
        cmd.pop();

    }

    cout << currTime << "\n";

}
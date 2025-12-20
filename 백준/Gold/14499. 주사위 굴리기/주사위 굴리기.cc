#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define UP 0
#define DOWN 1
using namespace std;

int row, col, diceY, diceX, cmdCnt;
int dice[6], arr[21][21], prevDice[6];
// 우, 좌, 상, 하
int dy[4] = {0, 0, -1, 1}, dx[4] = {1, -1, 0, 0};

void rollRight(){
    dice[0] = prevDice[5];
    dice[1] = prevDice[4];
    dice[2] = prevDice[2];
    dice[3] = prevDice[3];
    dice[4] = prevDice[0];
    dice[5] = prevDice[1];
}

void rollLeft(){
    dice[0] = prevDice[4];
    dice[1] = prevDice[5];
    dice[2] = prevDice[2];
    dice[3] = prevDice[3];
    dice[4] = prevDice[1];
    dice[5] = prevDice[0];
}

void rollUp(){
    dice[0] = prevDice[2];
    dice[1] = prevDice[3];
    dice[2] = prevDice[1];
    dice[3] = prevDice[0];
    dice[4] = prevDice[4];
    dice[5] = prevDice[5];
}

void rollDown(){
    dice[0] = prevDice[3];
    dice[1] = prevDice[2];
    dice[2] = prevDice[0];
    dice[3] = prevDice[1];
    dice[4] = prevDice[4];
    dice[5] = prevDice[5];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col >> diceY >> diceX >> cmdCnt;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    int dir;
    for(int i = 0; i < cmdCnt; i++){
        cin >> dir;
        dir--;
        int nextY = diceY + dy[dir];
        int nextX = diceX + dx[dir];

        if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;

        diceY = nextY;
        diceX = nextX;

        copy_n(dice, 6, prevDice);
        if(dir == 0) rollRight();
        else if(dir == 1) rollLeft();
        else if(dir == 2) rollUp();
        else rollDown();

        // 윗면 출력
        cout << dice[UP] << "\n";

        if(arr[nextY][nextX] == 0){
            arr[nextY][nextX] = dice[DOWN];
            continue;
        }

        // 지도에 적혀있는 수가 0이 아니면 바닥에 쓰여있는 수가 주사위의 바닥면으로 복사되고 칸에 쓰여있는 수는 0이됨
        dice[DOWN] = arr[nextY][nextX];
        arr[nextY][nextX] = 0;
    }

}
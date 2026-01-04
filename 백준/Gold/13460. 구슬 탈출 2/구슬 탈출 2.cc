#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define RED 1
#define BLUE 2
#define HOLE 3
using namespace std;

int row, col;
int moves[10];
pair<int, int> firstRed, firstBlue, hole, red, blue;
int firstArr[11][11], arr[11][11];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0}; // 좌 우 상 하

void moveRed(int dir){
    int currY = red.first;
    int currX = red.second;
    arr[currY][currX] = 0;

    while(true){
        if(currY == hole.first && currX == hole.second) break;

        int nextY = currY + dy[dir];
        int nextX = currX + dx[dir];

        if(arr[nextY][nextX] == -1 || arr[nextY][nextX] == BLUE) break;

        currY = nextY;
        currX = nextX;
    }
    red = {currY, currX};
    if(arr[currY][currX] != HOLE) arr[currY][currX] = RED;
}

void moveBlue(int dir){
    int currY = blue.first;
    int currX = blue.second;
    arr[currY][currX] = 0;

    while(true){
        if (currY == hole.first && currX == hole.second) break;

        int nextY = currY + dy[dir];
        int nextX = currX + dx[dir];

        if(arr[nextY][nextX] == -1 || arr[nextY][nextX] == RED) break;

        currY = nextY;
        currX = nextX;
    }

    blue = {currY, currX};
    if(arr[currY][currX] != HOLE) arr[currY][currX] = BLUE;
}

void moveLeft(){
    if(red.second < blue.second){
        moveRed(0);
        moveBlue(0);
        return;
    }
    moveBlue(0);
    moveRed(0);
}

void moveRight(){
    if(red.second > blue.second){
        moveRed(1);
        moveBlue(1);
        return;
    }
    moveBlue(1);
    moveRed(1);
}

void moveUp(){
    if(red.first < blue.first){
        moveRed(2);
        moveBlue(2);
        return;
    }
    moveBlue(2);
    moveRed(2);
}

void moveDown(){
    if(red.first > blue.first){
        moveRed(3);
        moveBlue(3);
        return;
    }
    moveBlue(3);
    moveRed(3);
}

bool perm(int size, int idx){
    if(idx == size){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                arr[i][j] = firstArr[i][j];
            }
        }
        red = firstRed;
        blue = firstBlue;
        for(int i = 0; i < size; i++){
            if(moves[i] == 0) moveLeft();
            else if(moves[i] == 1) moveRight();
            else if(moves[i] == 2) moveUp();
            else moveDown();
            if(blue == hole) return false;
            if(red == hole){
                return true;
            }
        }
        return false;
    }
    for(int i = 0; i < 4; i++){
        moves[idx] = i;
        bool isAns = perm(size, idx + 1);
        if(isAns) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    for(int i = 0; i < row; i++){
        string str;
        cin >> str;
        for(int j = 0; j < col; j++){
            char c = str[j];
            if(c == '.') continue; // 빈 칸
            if(c == '#') firstArr[i][j] = -1; // 벽
            else if(c == 'O'){ // 구멍
                firstArr[i][j] = HOLE;
                hole = {i, j};
                continue;
            }
            else if(c == 'R'){ // 빨강 공
                firstArr[i][j] = RED;
                firstRed = {i, j};
                continue;
            }
            else { // 파랑 공
                firstArr[i][j] = BLUE;
                firstBlue = {i, j};
            }
        }
    }

    int ans = -1 ;
    for(int i = 1; i <= 10; i++){
        bool isAns = perm(i, 0);
        if(!isAns) continue;
        ans = i;
        break;
    }
    cout << ans << "\n";

    return 0;
}
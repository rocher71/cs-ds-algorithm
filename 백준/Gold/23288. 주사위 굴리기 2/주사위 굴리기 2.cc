#include<iostream>
#include<algorithm>
#include<queue>
#include<array>
#include<vector>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
using namespace std;

int row, col, k, dir = 1, y = 0, x = 0;
int arr[21][21], visit[21][21];
array<int, 6> dice = {1, 2, 3, 4, 5, 6};
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1}; // 위 오 아래 왼

bool isOut(int y, int x){
    if(y < 0 || x < 0 || y >= row || x >= col) return true;
    return false;
}

void moveDice(int d){
    array<int, 6> tmpDice = dice;
    
    if(d == RIGHT) dice = {tmpDice[3], tmpDice[1], tmpDice[0], tmpDice[5], tmpDice[4], tmpDice[2]};
    else if(d == LEFT) dice = {tmpDice[2], tmpDice[1], tmpDice[5], tmpDice[0], tmpDice[4], tmpDice[3]};
    else if(d == UP) dice = {tmpDice[4], tmpDice[0], tmpDice[2], tmpDice[3], tmpDice[5], tmpDice[1]};
    else dice = {tmpDice[1], tmpDice[5], tmpDice[2], tmpDice[3], tmpDice[0], tmpDice[4]};
}

int getOppositeDir(int d){
    if(d == UP) return DOWN;
    if(d == DOWN) return UP;
    if(d == RIGHT) return LEFT;
    return RIGHT;
}

void rotateDir(bool isClockWise){
    // cout << "dir in rotateDir : " << dir << ", isClockWise : " << isClockWise << "\n";
    if(isClockWise){
        dir = (dir + 1) % 4;
        return;
    }
    if(--dir < 0) dir = 3;
}

int bfs(int num, int turn){
    int cnt = 0;
    queue<pair<int, int>> q;
    visit[y][x] = turn;
    q.push({y, x});
    
    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        
        cnt++;
        
        for(int i = 0; i < 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            
            if(isOut(nextY, nextX)) continue;
            if(visit[nextY][nextX] == turn || arr[nextY][nextX] != num) continue;
            
            visit[nextY][nextX] = turn;
            q.push({nextY, nextX});
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> row >> col >> k;
    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
    
    int ans = 0;
    for(int turn = 1; turn <= k; turn++){
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        
        if(isOut(nextY, nextX)) dir = getOppositeDir(dir);
        y = y + dy[dir];
        x = x + dx[dir];
        
        // 1. 주사위 이동
        moveDice(dir);
        
        // 2. 주사위 방향 결정
        int diceDownNum = dice[5];
        int writtenNum = arr[y][x];
        
        if(writtenNum > diceDownNum) rotateDir(false);
        else if(writtenNum < diceDownNum) rotateDir(true);
        
        // 3. 점수 획득
        int cnt = bfs(writtenNum, turn);
        // cout << "Turn " << turn << " : " << dir << " " << cnt << " " << writtenNum
        //     << " (" << y + 1 << ", " << x + 1 << ") dicedownNum : " << diceDownNum << ", writtenNum : " << writtenNum << "\n";
        ans += cnt * writtenNum;
    }
    cout << ans << "\n";
}


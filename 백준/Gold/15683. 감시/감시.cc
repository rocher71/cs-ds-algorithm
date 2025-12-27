#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, row, col, totalBlankCnt, getWatchCntNum = 1, maxWatchCnt;
pair<int, int> cctvLoc[8];
int cctvTypes[8], cctvPerm[8], visit[8][8], typePossibleCnt[5] = {4, 2, 4, 4, 1}, arr[8][8];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<vector<bool>> dir[5];

int getCnt(int y, int x, int currDir, int watchCntNum){
    int cnt = 0, currY = y, currX = x;
    while(true){
        int nextY = currY + dy[currDir];
        int nextX = currX + dx[currDir];
        if(nextY < 0 || nextX < 0 || nextY == row || nextX == col) break;
        
        currY = nextY;
        currX = nextX;
        if(arr[nextY][nextX] == 6) break;
        if(visit[nextY][nextX] == watchCntNum || arr[nextY][nextX] != 0) continue;
        
        visit[nextY][nextX] = watchCntNum;
        cnt++;
        
    }
    // cout << "\ny : " << y << ", x : " << x << " currDir : " << currDir << " watchCntNum : " << watchCntNum <<"\n";
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return cnt;
}

int getWatchCnt(int watchCntNum){
    int watchCntSum = 0;
    for(int num = 0; num < n; num++){
        int type = cctvTypes[num];
        int currDir = cctvPerm[num];
        for(int i = 0; i < 4; i++){
            if(!dir[type][currDir][i]) continue;
            watchCntSum += getCnt(cctvLoc[num].first, cctvLoc[num].second, i, watchCntNum);
        }
    }
    return watchCntSum;
}

void perm(int idx, int cctvNum){
    if(idx == n){
        // cout << "perm : ";
        // for(int i = 0; i < n; i++) cout << cctvPerm[i] << " ";
        // cout << "\n";
        maxWatchCnt = max(maxWatchCnt, getWatchCnt(getWatchCntNum++));
        // cout << "maxWatchCnt in perm() : " << maxWatchCnt << "\n";
        return;
    }
    int currCctvType = cctvTypes[cctvNum];
    // cout << "currCctvType : " << currCctvType << " typePossibleCnt[currCctvType] : " << typePossibleCnt[currCctvType] << "\n";
    for(int i = 0; i < typePossibleCnt[currCctvType]; i++){
        cctvPerm[idx] = i;
        perm(idx + 1, cctvNum + 1);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> row >> col;
    totalBlankCnt = row * col;
    
    dir[0] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    dir[1] = {{1, 0, 1, 0}, {0, 1, 0, 1}};
    dir[2] = {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1}};
    dir[3] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
    dir[4] = {{1, 1, 1, 1}};
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) continue;
            totalBlankCnt--;
            if(arr[i][j] == 6) continue;
            cctvLoc[n] = {i, j};
            cctvTypes[n++] = arr[i][j] - 1;
        }
    }
    
    if(n == 0){
        cout << totalBlankCnt << "\n";
        return 0;
    }
    
    perm(0, 0);
    // cout << totalBlankCnt << " " << maxWatchCnt << " ";
    cout << totalBlankCnt - maxWatchCnt << "\n";
}
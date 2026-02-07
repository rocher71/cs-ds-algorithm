#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
#define WALL 2
#define TARGET 1
using namespace std;

int row, col;
int arr[101][101], cnt[101][101][4];
pair<int, int> tOne, tTwo; // target 1, 2
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void bfs(){
//    fill(&cnt[0][0], &cnt[row-1][col], INT_MAX);
    queue<array<int, 4>> q; // 꺾인 횟수, 직전 방향, y, x

    for(int i = 0; i < 4; i++){
        q.push({0, i, tOne.first, tOne.second});
        cnt[tOne.first][tOne.second][i] = 0;
    }

    while(!q.empty()){
        int currCnt = q.front()[0];
        int prevD = q.front()[1];
        int y = q.front()[2];
        int x = q.front()[3];
        q.pop();
        if(currCnt > cnt[y][x][prevD]) continue;

//        if(y == tTwo.first && x == tTwo.second) return;

        for(int i = 0; i < 4; i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            int nextCnt = (i == prevD) ? currCnt : currCnt + 1;
            if(y == tOne.first && x == tOne.second) nextCnt = 0;

            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
            if(cnt[nextY][nextX][i] <= nextCnt) continue;
            if(arr[nextY][nextX] == WALL) continue;

            q.push({nextCnt, i, nextY, nextX});
            cnt[nextY][nextX][i] = nextCnt;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> col >> row;
    int tCnt = 0;
    for(int i = 0 ;i < row; i++){
        string str;
        cin >> str;
        for(int j = 0; j < col; j++){
            char c = str[j];
            if(c == '.') arr[i][j] = 0;
            else if(c == '*') arr[i][j] = WALL;
            else if(c == 'C') arr[i][j] = TARGET;

            if(c != 'C') continue;
            if(tCnt == 0){
                tOne.first = i;
                tOne.second = j;
                tCnt++;
                continue;
            }
            tTwo.first = i;
            tTwo.second = j;
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            for(int k = 0; k < 4; k++){
                cnt[i][j][k] = INT_MAX;
            }
        }
    }


    bfs();
//    for(int i = 0 ;i < row; i++){
//        for(int j = 0; j < col; j++){
//            for(int k = 0; k < 4; k++){
//                if(cnt[i][j][k] == INT_MAX) cout << "- ";
//                else cout << cnt[i][j][k] << " ";
//            }
//        }
//        cout << "\n";
//    }
//    cout << cnt[tTwo.first][tTwo.second] << "\n";
    int ans = INT_MAX;
    for(int i = 0; i < 4; i++) ans = min(ans, cnt[tTwo.first][tTwo.second][i]);
    cout << ans << "\n";
}


/*
4 12
C...
...*
....
....
*..*
....
....
*..*
....
*...
....
.C**

0 0 0 0
0 1 1 -
0 1 1 1
0 1 1 1
- 2 2 -
3 2 2 3
3 2 2 3
- 2 2 -
3 2 2 3
- 2 2 3
3 2 2 3
3 2 - -
2
 */
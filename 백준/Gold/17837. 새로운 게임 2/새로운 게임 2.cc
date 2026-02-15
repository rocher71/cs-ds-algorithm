#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<queue>
#include<array>
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

int n, k;
int color[13][13];
deque<int> chess[13][13];
int dy[5] = {0, 0, 0, -1, 1}, dx[5] = {0, 1, -1, 0, 0};
array<int, 3> pieceInfo[11]; // y, x, d

int getOppDir(int d){
    if(d == 1) return 2;
    if(d == 2) return 1;
    if(d == 3) return 4;
    return 3;
}

// d 0 이면 안바꿈
void changePieceInfo(int num, int y, int x, int d){
    pieceInfo[num] = {y, x, d == 0 ? pieceInfo[num][2] : d};
}

int getPieceIdx(int num){
    int y = pieceInfo[num][0];
    int x = pieceInfo[num][1];

    int idx = 0;
    for(int i = 0; i < chess[y][x].size(); i++){
        if(chess[y][x][i] != num) continue;
        idx = i;
        break;
    }
    return idx;
}

void movePieces(int y, int x, int nextY, int nextX, int idx, bool goOpposite){
    if(y == nextY && x == nextX) return;
    if(!goOpposite){
        for(int i = idx; i < chess[y][x].size(); i++){
            int num = chess[y][x][i];
            chess[nextY][nextX].push_back(num);
            changePieceInfo(num, nextY, nextX, 0);
        }
        int chessSize = chess[y][x].size();
        for(int i = 0; i < chessSize - idx; i++) chess[y][x].pop_back();
        return;
    }
    // 반대
    for(int i = chess[y][x].size() - 1; i >= idx; i--){
        int num = chess[y][x][i];
        chess[nextY][nextX].push_back(num);
        changePieceInfo(num, nextY, nextX, 0);
        chess[y][x].pop_back();
    }
}

bool isOut(int y, int x){
    if(y <= 0 || x <= 0 || y > n || x > n) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> color[i][j];
        }
    }

    for(int i = 1; i <= k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        pieceInfo[i] = {a, b, c};
        chess[a][b].push_back(i);
    }

    int ans = -1;
    for(int turn = 1; turn <= 1000; turn++){
//        cout << "Turn : " << turn << "\n";
        for(int i = 1; i <= k; i++){
            int y = pieceInfo[i][0];
            int x = pieceInfo[i][1];
            int d = pieceInfo[i][2];
            int newD = d;

            int nextY = y + dy[d];
            int nextX = x + dx[d];

            if(isOut(nextY, nextX) || color[nextY][nextX] == BLUE){
                newD = getOppDir(d);
                changePieceInfo(i, y, x, newD); // 여기선 방향만 바꿈
                nextY = y + dy[newD];
                nextX = x + dx[newD];
            }
            if(isOut(nextY, nextX)){
                nextY = y;
                nextX = x;
            }

            int currIdx = getPieceIdx(i);

            int nextColor = color[nextY][nextX];
            if(nextColor == WHITE) movePieces(y, x, nextY, nextX, currIdx, false);
            else if(nextColor == RED) movePieces(y, x, nextY, nextX, currIdx, true);
            // 이미 파랑은 방향을 한번 바꿨기 때문에 움직이지 않음.

//            cout << "After " << i << " piece move\n";
//            for(int j = 1; j <= k; j++){
//                cout << j << " : (" << pieceInfo[j][0] << ", " << pieceInfo[j][1] << "), d : " << pieceInfo[j][2] << "\n";
//            }


            if(chess[nextY][nextX].size() < 4) continue;
            ans = turn;
            break;
        }
        if(ans != -1) break;
    }

    cout << ans << "\n";
}



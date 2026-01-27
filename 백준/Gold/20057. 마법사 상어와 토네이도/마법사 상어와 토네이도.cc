#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n;
int arr[500][500];
// 좌, 우, 상, 하, 알파, y
// 1%, 7%, 10%, 2%, 5% 순
int dy[4][11] = {{-1, 1, -1, 1,-1, 1, -2, 2, 0, 0, 0},
                 {-1, 1, -1, 1,-1, 1, -2, 2, 0, 0, 0},
                 {0, 0, -1, -1, -2, -2, -1, -1, -3, -2, -1},
                 {0, 0, 1, 1, 2, 2, 1, 1, 3, 2, 1}};
int dx[4][11] = {{0, 0, -1, -1, -2, -2, -1, -1, -3, -2, -1},
                 {0, 0, 1, 1, 2, 2, 1, 1, 3, 2, 1},
                 {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0, 0},
                 {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0, 0}};

bool isOut(int y, int x){
    if(y < 0 || x < 0 || y >= n || x >= n) return true;
    return false;
}

void move(int y, int x, int d){
    int alphaY = y + dy[d][9];
    int alphaX = x + dx[d][9];

    int dustY = y + dy[d][10];
    int dustX = x + dx[d][10];

    int movedSum = 0, toMove = arr[dustY][dustX];
    arr[dustY][dustX] = 0;

    for(int i = 0;i < 5; i++){
        for(int j = 0; j < 2; j++){
            int nextD = i * 2 + j;
            int nextY = y + dy[d][nextD];
            int nextX = x + dx[d][nextD];

            int per;
            if(i == 0) per = 1;
            else if(i == 1) per = 7;
            else if(i == 2) per = 10;
            else if(i == 3) per = 2;
            else if(i == 4) per = 5;

            int currDust = toMove * per / 100;
            movedSum += currDust;

            if(isOut(nextY, nextX)) continue;

            arr[nextY][nextX] += currDust;
            if(i == 4) break;
        }
    }

    if(isOut(alphaY, alphaX)) return;

    arr[alphaY][alphaX] += toMove - movedSum;
}

void print(int y, int x, string stage){
    return;
    cout << "\nAfter " << stage << " : " << y <<", " << x << "\n";
    for(int k = 0; k < n; k++){
        for(int j = 0; j < n; j++){
            cout << arr[k][j] << " ";
        }
        cout << "\n";
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int initialSum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            initialSum += arr[i][j];
        }
    }

    bool isLeft = true;
    int y = n / 2, x = n / 2, cnt = 1;
    while(!(y == 0 && x == 0)){
        if(y == 0 && x == 0) break;
        for(int i = 0; i < cnt; i++){
            if(y == 0 && x == 0) break;
            if(isLeft){
                move(y, x, 0);
                x--;
                print(y, x, "left");
                continue;
            }
            move(y, x, 1);
            x++;
            print(y, x, "right");
        }
        for(int i = 0; i < cnt; i++){
            if(y == 0 && x == 0) break;

            if(isLeft){
                move(y, x, 3);
                y++;
                print(y, x, "down");
                continue;
            }
            move(y, x, 2);
            y--;
            print(y, x, "up");
        }
        isLeft = !isLeft;
        cnt++;
    }

    int inSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            inSum += arr[i][j];
        }
    }
    cout << initialSum - inSum << "\n";
}
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int n, minDiff = INT_MAX;
int pplCnt[6];
int arr[21][21], area[21][21];
int dx[6] = {1, 1, 0, 0, -1, 1}, dy[6] = {-1, 1, 1, -1, 0, 0}; // 좌하강, 우하강

bool isOut(int x, int y){
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}


void areaBfs(int x, int y, int areaNum, pair<int, int> leftEnd, pair<int, int> rightEnd){
    queue<pair<int, int>> q;
    area[x][y] = areaNum;
    q.push({x, y});

    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i = 2; i < 6; i++){
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];

            if(isOut(nextX, nextY)) continue;
            if(area[nextX][nextY] != 0) continue;
            if(areaNum == 1 && (nextX > leftEnd.first || nextY > rightEnd.second)) continue;
            if(areaNum == 2 && (nextX > rightEnd.first || nextY < leftEnd.second)) continue;
            if(areaNum == 3 && (nextX < leftEnd.first || nextY > rightEnd.second)) continue;
            if(areaNum == 4 && (nextX < rightEnd.first || nextY < leftEnd.second)) continue;

            area[nextX][nextY] = areaNum;
            q.push({nextX, nextY});
        }
    }
}

int countPopulation(int x, int y, int d1, int d2, int turn){
    for(int i = 1; i <= 5; i++) pplCnt[i] = 0;

    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // 5선거구
            if(area[i][j] == 5){
                pplCnt[5] += arr[i][j];
                continue;
            }

            if(i < x + d1 && j <= y){
                area[i][j] = 1;
                pplCnt[1] += arr[i][j];
            }
            if(i <= x + d2 && j > y){
                area[i][j] = 2;
                pplCnt[2] += arr[i][j];
            }
            if(i >= x + d1 && j < y - d1 + d2){
                area[i][j] = 3;
                pplCnt[3] += arr[i][j];
            }
            if(i > x + d2 && j >= y - d1 + d2){
                area[i][j] = 4;
                pplCnt[4] += arr[i][j];
            }
        }
    }*/

    areaBfs(1, 1, 1, {x + d1 - 1, y - d1}, {x - 1, y});
    areaBfs(1, n, 2, {x - 1, y + 1}, {x + d2 , y + d2 + 1});
    areaBfs(n, 1, 3, {x + d1, y - d1 - 1}, {x + d1 + d2, y - d1 + d2 - 1});
    areaBfs(n, n, 4, {x + d1 + d2 + 1, y - d1 + d2}, {x + d2 + 1, y + d2});

//    if(x == 1 && y == 2 && d1 == 1 && d2 == 7){
//    cout << "In countPopulation :\n";
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            if(area[i][j] == 5 || area[i][j] == 0) {
//                cout << "5 ";
                pplCnt[5] += arr[i][j];
                continue;
            }
//            cout << area[i][j] << " ";

            if(area[i][j] == 1) pplCnt[1] += arr[i][j];
            else if(area[i][j] == 2) pplCnt[2] += arr[i][j];
            else if(area[i][j] == 3) pplCnt[3] += arr[i][j];
            else if(area[i][j] == 4) pplCnt[4] += arr[i][j];
        }
//        cout << "\n";
    }
//    cout << "\n";
//    for(int i = 1; i <= 5; i++) cout << i << " : " << pplCnt[i] << "\n";
//    }

    // 선거구 중 하나라도 인구가 없는 곳(구역 할당이 안된 곳)이 있으면 무효
    int maxCnt = 0, minCnt = INT_MAX;
    for(int i = 1; i <= 5; i++){
        if(pplCnt[i] == 0) return -1;
        maxCnt = max(maxCnt, pplCnt[i]);
        minCnt = min(minCnt, pplCnt[i]);
    }


    return abs(maxCnt - minCnt);
}

 void bfs(int x, int y, int d1, int d2, int turn){
     queue<pair<int, int>> q;
     area[x + 1][y] = 5;
     q.push({x + 1, y});

     // 2345
     while(!q.empty()){
         int currX = q.front().first;
         int currY = q.front().second;
         q.pop();

         for(int i = 2; i <= 5; i++){
             int nextX = currX + dx[i];
             int nextY = currY + dy[i];

             if(isOut(nextX, nextY)) continue;
             // 경계선 내부만을 표시하기 위해 경계선 만나면 continue
             if(area[nextX][nextY] == 5) continue;
             if(nextX >= x || nextX <= x + d1 + d2 || n <= y - d1 || y >= y + d2) continue;

             area[nextX][nextY] = 5;
             q.push({nextX, nextY});
         }
     }
 }

void markFifth(int x, int y, int d1, int d2, int turn) {
    fill(&area[0][0], &area[n][n + 1], 0);
    area[x][y] = 5;
    area[x + d1][y - d1] = 5;
    area[x + d2][y + d2] = 5;
    area[x + d1 + d2][y - d1 + d2] = 5;

    // if(x == 1 && y == 2 && d1 == 1 && d2 == 7){
    //     cout << "In markFifth : \n";
    //     for(int k = 1; k<= n; k++){
    //         for(int j = 1; j <= n; j++){
    //             if(area[k][j] != 5) cout << "0 ";
    //             else cout << area[k][j] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }


    for (int i = 1; i <= n; i++) {
        // if(x == 1 && y == 2 && d1 == 1 && d2 == 7){
        //     for(int k = 1; k<= n; k++){
        //         for(int j = 1; j <= n; j++){
        //             if(area[k][j] != 5) cout << "0 ";
        //             else cout << area[k][j] << " ";
        //         }
        //         cout << "\n";
        //     }
        //     cout << "\n";
        // }

        int outCnt = 0;
        // 1번 경계선
        int nextX = x + dx[0] * i;
        int nextY = y + dy[0] * i;
        if (isOut(nextX, nextY)) outCnt++;
        else if (nextX <= x + d1 && nextY >= y - d1) {
            area[nextX][nextY] = 5;
            if (nextX != x + d1 && nextY != y - d1) area[nextX][nextY + 1] = 5;
        }

        // 2번 경계선
        nextX = x + dx[1] * i;
        nextY = y + dy[1] * i;
        if (isOut(nextX, nextY)) outCnt++;
        else if (nextX <= x + d2 && nextY <= y + d2) {
            area[nextX][nextY] = 5;
            area[nextX][nextY - 1] = 5;
        }

        // 3번 경계선
        nextX = x + d1 + dx[1] * i;
        nextY = y - d1 + dy[1] * i;
        if (isOut(nextX, nextY)) outCnt++;
        else if (nextX <= x + d1 + d2 && nextY <= y - d1 + d2) {
            area[nextX][nextY] = 5;
            if (nextX != x + d1 + d2 && nextY != y - d1 + d2) area[nextX][nextY + 1] = 5;
        }


        // 4번 경계선
        nextX = x + d2 + dx[0] * i;
        nextY = y + d2 + dy[0] * i;
        if (isOut(nextX, nextY)) outCnt++;
        else if (nextX <= x + d1 + d2 && nextY >= y - d1 + d2) {
            area[nextX][nextY] = 5;
            if (nextX != x + d1 + d2 && nextY != y - d1 + d2) area[nextX][nextY - 1] = 5;
        }

        if (outCnt == 4) break;
    }

    bfs(x, y, d1, d2, turn);

    /*
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (area[i][j] != 5) cout << "- ";
//            else cout << area[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";


    // cout << "After BFS : \n";
//     bfs(x, y, d1, d2, turn);
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            if(i > x && i < x + d1 + d2 && j > y - d1 &&  j < y + d2) area[i][j] = 5;
//        }
//    }

//    if(x == 1 && y == 2 && d1 == 1 && d2 == 7){
//        for(int i = 1; i<= n; i++){
//            for(int j = 1; j <= n; j++){
//                if(area[i][j] != 5) cout << "0 ";
//                else cout << area[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//    }
     */
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    int turn = 10;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // 네 꼭지점은 선거구 조건 만족 못하므로 패스
            if((i == 1 && j == 1)
               || (i == 1 && j == n)
               || (i == n && j == 1)
               || (i == n && j == 1)
                    ) continue;

            int d1 = 0;
            int d2 = 0;
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    // 경계선 조건
                    if(i >= i + k + l) continue;
                    if(i + k + l > n) continue;
                    if(j - k < 1) continue;
                    if(j - k >= j) continue;
                    if(j >= j + l) continue;
                    if(j + l > n) continue;

//                    cout << "x y d1 d2 turn\n"
//                         << i << " " << j << " " << k << " " << l << " " << turn << "\n";

                    markFifth(i, j, k, l, turn);
                    int diff = countPopulation(i, j, k, l, turn);
                    turn++;
                    if(diff == -1) continue;
                    minDiff = min(minDiff, diff);

                    // for(int m = 1; m <= 5; m++) cout << m << " : " << pplCnt[m] << "\n";
//                     cout << "diff : " << diff << "\nminDiff : " << minDiff << "\n";

                    // cout << "===================================================\n";

                }
            }

        }
    }

    cout << minDiff << "\n";
}




#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define SHARK -1
using namespace std;

int maxFishSum;
int arr[4][4];
pair<pair<int, int>, int> fishLoc[17];
int dy[8] = {-1, -1, 0, 1, 1,1, 0, -1}, dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}; // 위 부터 반시계

bool isInArr(int y, int x){
    if(y < 0 || x < 0 || y >= 4 || x >= 4) return false;
    return true;
}

int moveShark(int y, int x, int fishNum, int prevY, int prevX){
//    cout << "In move shark (prevY, prevX) :  " << prevY << ", " << prevX;
//    cout << " (newY, newX) : " << y << ", " << x << ", newD : " << fishLoc[fishNum].second;
//    cout << ", fishNum : " << fishNum << "\n";
    fishLoc[fishNum].first = {-1, -1};
    arr[y][x] = SHARK;
    if(prevY != -1) arr[prevY][prevX] = 0;
    return fishLoc[fishNum].second;
}

void moveFish(int fishNum){
    int y = fishLoc[fishNum].first.first;
    int x = fishLoc[fishNum].first.second;
    int dir = fishLoc[fishNum].second;
    if(y == -1 || x == -1) return;
//    if(fishNum == 15) cout << "fish 15 loc1 : " << y << ", " << x << " d : " << dir << "\n";

    for(int i = 0 ; i < 8; i++){
        int nextD = (dir + i) % 8;
        int nextY = y + dy[nextD];
        int nextX = x + dx[nextD];

        if(!isInArr(nextY, nextX)) continue;
        if(arr[nextY][nextX] == SHARK) continue;

        // 이동할 칸에 있는 물고기를 현재 칸으로
        int nextLocFishNum = arr[nextY][nextX];
        // if(nextLocFishNum != 0){
        //     arr[y][x] = nextLocFishNum;
        //     fishLoc[nextLocFishNum].first = {y, x};
        // }
        arr[y][x] = nextLocFishNum;
        if(nextLocFishNum != 0) fishLoc[nextLocFishNum].first = {y, x};

        // 현재 칸 -> 다음 칸
        arr[nextY][nextX] = fishNum;
        fishLoc[fishNum] = {{nextY, nextX}, nextD};

//        if(fishNum == 15) cout << "fish 15 loc2 : " << nextY << ", " << nextX << " d : " << nextD << "\n";
        break;
    }

    // cout << "\nAfter move fish " << fishNum << "\n";
    //     for(int j = 0; j < 4; j++){
    //         for(int k = 0; k < 4; k++){
    //             if(arr[j][k] == SHARK) cout << "* ";
    //             else cout << arr[j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";

    return;
}

void sharkDfs(int y, int x, int currFishSum, int sharkD){
//    if(currFishSum >= 40) return;

    int currArr[4][4];
    pair<pair<int, int>, int> currFishLoc[17];
    for(int i = 0; i< 4; i++){
        for(int j = 0; j < 4; j++){
            currArr[i][j] = arr[i][j];
        }
    }
    for(int i = 1; i <= 16; i++) currFishLoc[i] = fishLoc[i];
    // if(y == 1 && x == 1) return;
//    cout << "InSharkDfs (y, x) : " << y << ", " << x << ", " << currFishSum << " " << sharkD << "\n";
//    for(int i = 0; i < 4; i++){
//        for(int j = 0; j < 4; j++){
//            if(arr[i][j] == SHARK) cout << "* ";
//            else cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    for(int i = 1; i <= 3; i++){
        int nextY = y + (dy[sharkD] * i);
        int nextX = x + (dx[sharkD] * i);

        if(!isInArr(nextY, nextX)) continue;
        if(!arr[nextY][nextX]) continue; // 물고기 없음

        int eatenFishNum = arr[nextY][nextX];
        // arr[y][x] = 0; // 현재 칸 비우기
        int newFishSum = currFishSum + arr[nextY][nextX];
        int newSharkDir = moveShark(nextY, nextX, arr[nextY][nextX], y, x);

//        cout << "\nAfter shark move\n";
//        for(int j = 0; j < 4; j++){
//            for(int k = 0; k < 4; k++){
//                if(arr[j][k] == SHARK) cout << "* ";
//                else cout << arr[j][k] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        // for(int j = 1; j <= 16; j++){
        //     cout << j << " " <<
        //         fishLoc[j].first.first << " " << fishLoc[j].first.second << " " << fishLoc[j].second << "\n";
        // }

        for(int j = 1; j <= 16; j++){
            if(fishLoc[j].first.first == -1) continue;
            moveFish(j);
        }

        // for(int j = 1; j <= 16; j++){
        //     cout << j << " " <<
        //         fishLoc[j].first.first << " " << fishLoc[j].first.second << " " << fishLoc[j].second << "\n";
        // }

//        cout << "\nAfter fish move\n";
//        for(int j = 0; j < 4; j++){
//            for(int k = 0; k < 4; k++){
//                if(arr[j][k] == SHARK) cout << "* ";
//                else cout << arr[j][k] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        // return;

        sharkDfs(nextY, nextX, newFishSum, newSharkDir);

        // fishLoc[eatenFishNum].first = {nextY, nextX};
        // arr[nextY][nextX] = eatenFishNum;
        // arr[y][x] = SHARK;
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                arr[j][k] = currArr[j][k];
            }
        }
        for(int j = 1; j <= 16; j++) fishLoc[j] = currFishLoc[j];
    }



    maxFishSum = max(maxFishSum, currFishSum);
//    cout << "maxFishSum : " << maxFishSum << ", currFishSum : " << currFishSum << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0 ;i < 4; i++){
        for(int j = 0; j < 4; j++){
            int fishNum, dir;
            cin >> fishNum >> dir;
            arr[i][j] = fishNum;
            fishLoc[fishNum] = {{i, j}, dir - 1};
        }
    }

    int firstFish = arr[0][0];
    int firstD = moveShark(0, 0, firstFish, -1, -1);
    // fishLoc[firstFish].first = {-1, -1};
    for(int i = 1; i <= 16; i++){
        if(fishLoc[i].first.first == -1) continue;
        moveFish(i);
    }

    // for(int i = 1; i <= 16; i++){
    //   cout << i << " " <<
    //     fishLoc[i].first.first << " " << fishLoc[i].first.second << " " << fishLoc[i].second << "\n";
    // }

    sharkDfs(0, 0, firstFish, firstD);

    cout << maxFishSum << "\n";
}







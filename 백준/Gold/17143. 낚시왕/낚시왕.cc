#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int row, col, sharkCnt;
int arr[101][101], times[101][101]; // arr[r][c] = x, times[r][c] = a : r, c에 있는 x번 상어는 a 번째 for 문에서 지정된 위치
unordered_map<int, vector<int>> sharks; // sharks[x] = {r, c, s, d, z} : x번 상어의 정보 (위치 r, c, 속도 s, 방향 d, 크기 z)
// 0, 위, 아래, 오른쪽, 왼쪽
int dy[5] = {0, -1, 1, 0, 0},
    dx[5] = {0, 0, 0, 1, -1};
vector<int> rowMoves, colMoves;
unordered_set<int> toDeleteSharks;

void deleteShark(int sharkNum){
    // arr 에서 삭제
    int sharkY = sharks[sharkNum][0];
    int sharkX = sharks[sharkNum][1];
    arr[sharkY][sharkX] = 0;

    // sharks 에서 삭제
    sharks.erase(sharkNum);
}

// 가장 땅과 가까이 있는 상어를 찾고 사이즈를 리턴
// 찾은 뒤 해당 상어는 삭제
// 해당 열에 상어가 없으면 0 리턴
int findMinYSharkSize(int c){
    for(int i = 0; i < row; i++){
        if(!arr[i][c]) continue;
        int caughtSharkSize = sharks[arr[i][c]][4];
        deleteShark(arr[i][c]);
        return caughtSharkSize;
    }
    return 0;
}

void moveShark(int sharkNum, int time){
    int y = sharks[sharkNum][0];
    int x = sharks[sharkNum][1];
    int speed = sharks[sharkNum][2];
    int d = sharks[sharkNum][3];
    int size = sharks[sharkNum][4];
    int newY = y, newX = x, newD = d;

    if(d == 1){ // 위
        newY = rowMoves[abs(y - speed) % rowMoves.size()];
//        newD = (abs(y - speed) % row) % 2 == 0 ? 2 : d;
        newD = (y - speed >= 0 && y - speed < row) || ((abs(y-speed) - 1) / (row - 1)) % 2 != 0 ? d : 2;
    } else if(d == 2){ // 아래
        newY = rowMoves[(y + speed) % rowMoves.size()];
//        newD = ((y + speed) % row) % 2 == 0 ? 1 : d;
        newD = (y + speed >= 0 && y + speed < row) || ((abs(y+speed) - 1) / (row - 1)) % 2 == 0 ? d : 1;
    } else if(d == 3){ // 오른쪽
        newX = colMoves[(x + speed) % colMoves.size()];
//        newD = ((x + speed) % col) % 2 == 0 ? 4 : d;
        newD = (x + speed >= 0 && x +  speed < col) || ((abs(x + speed) - 1) / (col - 1)) % 2 == 0 ? d : 4;
    } else if(d == 4){ // 왼쪽
        newX = colMoves[abs(x - speed) % colMoves.size()];
//        newD = (abs(x - speed) % col) % 2 == 0 ? 3 : d;
        newD = (x - speed >= 0 && x -  speed < col) || ((abs(x - speed) - 1) / (col - 1)) % 2 != 0 ? d : 3;
    }

    // 기존 arr, times 제거
    // 이때 새로운 상어가 기존 자리에 도착했을 수도 있으므로 y, x가 현재 상어 번호와 같은지 체크
    if(arr[y][x] == sharkNum){
        arr[y][x] = 0;
        times[y][x] = 0;
    }

    // 새로운 자리에 이번 턴에 옮겨진 나보다 더 큰 상어가 있는 경우 (내가 잡아 먹힘) && 지워야할(이미 먹힌) 상어가 아닌경우
    if(arr[newY][newX] && times[newY][newX] == time && sharks[arr[newY][newX]][4] > size && toDeleteSharks.find(arr[newY][newX]) == toDeleteSharks.end()){
//        deleteShark(sharkNum);
        toDeleteSharks.insert(sharkNum);
        return;
    }

    // 새로운 자리에 이번 턴에 옮겨진 나보다 더 작은 상어가 있는 경우 (내가 잡아 먹음)
    if(arr[newY][newX] && times[newY][newX] == time && sharks[arr[newY][newX]][4] < size && toDeleteSharks.find(arr[newY][newX]) == toDeleteSharks.end()){
//        deleteShark(arr[newY][newX]);
        toDeleteSharks.insert(arr[newY][newX]);
    }

    arr[newY][newX] = sharkNum;
    times[newY][newX] = time;
    sharks[sharkNum] = {newY, newX, speed, newD, size};

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col >> sharkCnt;
    if(sharkCnt == 0){
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < row; i++) rowMoves.push_back(i);
    for(int i = row - 2; i >= 1; i--) rowMoves.push_back(i);

    for(int i = 0; i < col; i++) colMoves.push_back(i);
    for(int i = col - 2; i >= 1; i--) colMoves.push_back(i);

    for(int i = 1; i <= sharkCnt; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks.insert({i, {r - 1, c - 1, s, d, z}});
        arr[r - 1][c - 1] = i;
        times[r - 1][c - 1] = -1;
    }

//    for(int j = 0; j < row; j++){
//        for(int k = 0 ; k < col; k++){
//            if(arr[j][k]) cout << sharks[arr[j][k]][4] << " ";
//            else cout << arr[j][k] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    int caughtSharkSum = 0;
    for(int i = 0; i < col; i++){
        // 1. 가장 땅에 가까운 상어 잡기 (예외처리는 함수에서 되어있음)
        caughtSharkSum += findMinYSharkSize(i);
//        cout << "\ni : " << i << " " << caughtSharkSum << "\n";

        if(i == col) break;
        // 2. 상어 이동
        for(auto shark : sharks){
            // 지워야할 상어라면 패스
            if(toDeleteSharks.find(shark.first) != toDeleteSharks.end()) continue;
            moveShark(shark.first, i);
        }
//        for(int j = 0; j < row; j++){
//            for(int k = 0 ; k < col; k++){
//                if(arr[j][k]) cout << sharks[arr[j][k]][4] << " ";
//                else cout << arr[j][k] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
    }

    cout << caughtSharkSum << "\n";

}
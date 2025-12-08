#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
bool arr[102][102];
int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};

pair<int, int> getNewLoc(int currY, int currX, int pointY, int pointX){
    int yDiff = currY - pointY;
    int xDiff = currX - pointX;
    return {pointY + xDiff, pointX - yDiff};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int maxY = -1;
    // 드래곤 커브 순회
    for(int i = 0 ;i < N; i++){
        set<pair<int, int>> locs;
        int startX, startY, direction, generation;
        cin >> startX >> startY >> direction >> generation;

        // 0세대
        int pointY = startY + dy[direction];
        int pointX = startX + dx[direction];
        locs.insert({startY, startX});
        locs.insert({pointY, pointX});
        arr[startY][startX] = true;
        arr[pointY][pointX] = true;

        maxY = max(startY, pointY);

        int newPointY = startY, newPointX = startX, maxDist = 0;
        // i번 드래곤 커브의 세대 순회
        for(int j = 1; j <= generation; j++){
            vector<pair<int, int>> newLocs;
            for(auto loc : locs){
                pair<int, int> newLoc = getNewLoc(loc.first, loc.second, pointY, pointX);
                if(newLoc.first > 100 || newLoc.second > 100 || newLoc.first < 0 || newLoc.second < 0) continue;

                newLocs.push_back(newLoc);
                arr[newLoc.first][newLoc.second] = true;
                maxY = max(maxY, newLoc.first);

                // 다음 세대의 끝점 설정을 위한 계산
                if(j == generation) continue;
                // 끝점은 항상 시작점의 새로운 위치
                if(loc.first != startY || loc.second != startX) continue;
                newPointY = newLoc.first;
                newPointX = newLoc.second;
            }
            for(auto loc : newLocs) locs.insert(loc);
            pointY = newPointY;
            pointX = newPointX;
        }

//        cout << "\n" << i << "번 드래곤 커브 추가\n";
//        for(int j = 0; j <= 10; j++){
//            for(int k = 0; k <= 10; k++){
//                cout << arr[j][k] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
    }

//    for(int i = 0; i<= 101; i++){
//        for(int j = 0; j <= 101; j++){
//            cout << arr[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    int answerCnt = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j<= 100; j++){
            if(!arr[i][j]) continue;
            if(arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) answerCnt++;
        }
    }


    cout << answerCnt << "\n";
}

#include <iostream>
#include <climits>
#include <queue>
using namespace std;

int tc, row, col, startY, startX;
int arr[1001][1001], fire[1001][1001];
bool visitEscape[1001][1001], visitFire[1001][1001];
int dy[4]= {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};
vector<pair<int, int>> fires;

void bfs(bool isFire){
    queue<pair<int, int>> q;
    if(isFire) for(auto yx : fires){
        q.push({yx.first, yx.second});
        visitFire[yx.first][yx.second] = true;
    }
    else{
        q.push({startY, startX});
        visitEscape[startY][startX] = true;
    }

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            // 범위가 벗어난 경우 & 벽이 있는 경우 pass
            if(nextY <0 || nextX < 0 || nextY >= row || nextX >= col || arr[nextY][nextX] == -1) continue;

            /*
             * 1. 상근이 bfs
             * 1) 다음 정점을 이미 방문 했을 시 pass
             * 2) 다음 정점을 불이 이미 방문 했는데, 그 시간이 현재 정점의 시간보다 적을때, 즉 불이 먼저 퍼진 곳일때 pass
             */
            if(!isFire && (visitEscape[nextY][nextX] || (visitFire[nextY][nextX] == true && fire[nextY][nextX] <= arr[currY][currX] + 1))) continue;
            if(isFire && visitFire[nextY][nextX]) continue;

            // 상근이 bfs, 시간 갱신, q에 push, visit 배열 갱신
            if(!isFire){
                arr[nextY][nextX] = arr[currY][currX] + 1;
                q.push({nextY, nextX});
                visitEscape[nextY][nextX] = true;
                continue;
            }
            // 불, 시간 갱신, q에 push, visit 배열 갱신
            fire[nextY][nextX] = fire[currY][currX] + 1;
            q.push({nextY, nextX});
            visitFire[nextY][nextX] = true;
        }
    }
}

int main(){
    cin >> tc;
    while(tc--){
        cin >> col >> row;

        // 배열 및 변수 초기화
        startY = -1, startX = -1;
        fires.clear();
        fill(arr[0], arr[row], 0);
        fill(fire[0], fire[row], 0);
        fill(visitFire[0], visitFire[row], false);
        fill(visitEscape[0], visitEscape[row], false);

        for(int i = 0; i< row; i++){
            string str;
            cin >> str;
            for(int j = 0; j< col; j++){
                if(str[j] == '.') continue; // 갈 수 있는 곳

                if(str[j] == '#') arr[i][j] = -1; // 벽
                else if(str[j] ==  '*') fires.push_back({i, j}); // 불
                else if(str[j] == '@'){ // 시작점
                    startY = i;
                    startX = j;
                }
            }
        }

        // 상근이 위치가 입력 되지 않은경우 바로 impossible 출력
        if(startY == -1 && startX == -1){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        bfs(true);
        bfs(false);

        int minOut = INT_MAX;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0; j< col ; j++){
                if(i != 0 && j != 0 && i != row - 1 && j != col - 1) continue; // 모서리만 탐색
                // 시작점이 모서리일 경우 바로 1출력
                if(startY == i && startX == j){
                    minOut = 0;
                    break;
                }
                if(arr[i][j] == -1 || arr[i][j] == 0) continue; // 벽이거나 방문하지 못 한 곳일때 pass


                minOut = min(minOut, arr[i][j]);
            }
            if(minOut == 0) break; // 모서리인 경우
        }

        if(minOut == INT_MAX){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << minOut + 1 << "\n";
    }
}

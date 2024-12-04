// 4 방향 모두 처리하는 부분, row, col이 0 or row, col 일 경우 처리를 잘 하자

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int row, col, departY, departX;
int maze[1001][1001], dist[1001][1001], fire[1001][1001];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0,};
vector<pair<int, int>> fires;
bool isBlocked = true;

void bfs(bool isFire){
    queue<pair<int, int>> q;
    if(isFire){
        for(auto location : fires) q.push({location.first, location. second});
    } else{
        q.push({departY, departX});
    }

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            // 못가는 경우
            if(nextY <0 || nextX < 0 || nextY >= row || nextX >= col || maze[nextY][nextX] == -1) continue;
            if(isFire && fire[nextY][nextX] <= fire[currY][currX] + 1) continue;
            if(!isFire && (dist[nextY][nextX] <= dist[currY][currX] + 1 || fire[nextY][nextX] <= dist[currY][currX] + 1)) continue;

            q.push({nextY, nextX});
            if(isFire) fire[nextY][nextX] = fire[currY][currX] + 1;
            else dist[nextY][nextX] = dist[currY][currX] + 1;
        }
    }

}

int main(){
    cin >> row >> col;

    fill(dist[0], dist[row], INT_MAX);
    fill(fire[0], fire[row], INT_MAX);

    for(int i = 0; i< row; i++){
        string str;
        cin >> str;
        for(int j = 0; j < col; j++){
            if(str[j] == '#') maze[i][j] = -1;
            else if(str[j] == 'F'){
                fire[i][j] = 0;
                fires.push_back({i, j});
                continue;
            }
            else if(str[j] == 'J'){
                // J 입력
                dist[i][j] = 0;
                departY = i;
                departX = j;
                if(i == 0 || j == 0 || i == row - 1 || j == col - 1) isBlocked = false;
                continue;
            }

            if(str[j] == '.' && (i == row - 1 || j == col - 1 || i == 0 || j == 0)) isBlocked = false;
        }
    }

    if(isBlocked){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    bfs(true); // 불 bfs
    bfs(false); // 지훈 bfs

    int minExit = INT_MAX;
    for(int i = 0; i< row; i++){
        for(int j = 0; j< col; j++){
            if(i != row -1 && j != col - 1 && i != 0 && j != 0) continue;
            if(maze[i][j] == -1) continue;
            minExit = min(minExit, dist[i][j]);
        }
    }

    if(minExit == INT_MAX){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << minExit + 1 << "\n";
    return 0;

}

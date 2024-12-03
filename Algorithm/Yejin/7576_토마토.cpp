#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int row, col, initialSum, maxDays, noTomatoCnt;
int visit[1001][1001], days[1001][1001], tomato[1001][1001];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void bfs(){
    queue<pair<int, int>> q;

    // bfs를 여러번 돌리지 않고, 한번에 토마토를 큐에 넣어야 시간초과가 나지 않음!
    for(int i = 0; i< row; i++){
        for(int j = 0; j< col; j++){
            if(tomato[i][j] != 1) continue;
            q.push({i, j});
            days[i][j] = 0;
        }
    }

//    if(days[startY][startX] == INT_MAX) days[startY][startX] = 0;
//    visit[startY][startX] = true;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
            if(tomato[nextY][nextX] || tomato[nextY][nextX] == -1 || days[nextY][nextX] <= days[currY][currX] + 1) continue;

            days[nextY][nextX] = days[currY][currX] + 1;
            q.push({nextY, nextX});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> col >> row;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == 1) initialSum++;
            if(tomato[i][j] == -1) noTomatoCnt++;
        }
    }

    fill(days[0], days[row], INT_MAX);

    // 저장할 때부터 모든 토마토가 익어있는 상태
    if(initialSum == row* col - noTomatoCnt){
        cout << "0\n";
        return 0;
    }

    // 토마토가 모두 익지 못하는 상황
    if(initialSum == 0){
        cout << "-1\n";
        return 0;
    }

    bfs();

    for(int i = 0; i< row; i++){
        for(int j = 0; j< col ; j++){
            if(days[i][j] != INT_MAX) maxDays = max(maxDays, days[i][j]);
            if(tomato[i][j] != -1 && days[i][j] == INT_MAX){
                cout << "-1\n";
                return 0;
            }

        }
    }


    cout << maxDays << "\n";


}

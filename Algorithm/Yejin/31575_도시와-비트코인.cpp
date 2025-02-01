#include <iostream>
#include <queue>
using namespace std;

int row, col;
int dy[2] = {0, 1},
    dx[2] = {1, 0};
bool visit[301][301], arr[301][301];

void bfs(){
    queue<pair<int, int>> q;
    visit[0][0] = true;
    q.push({0, 0});

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        if(currY == row - 1 && currX == col - 1) return;

        for(int i = 0; i< 2; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
            if(visit[nextY][nextX] || arr[nextY][nextX] == 0) continue;

            q.push({nextY, nextX});
            visit[nextY][nextX] = true;
        }
    }
}

int main(){
    cin >> col >> row;
    for(int i = 0; i< row; i++){
        for(int j = 0; j< col; j++) cin >> arr[i][j];
    }

    bfs();

    if(!visit[row-1][col-1]){
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    return 0;
}

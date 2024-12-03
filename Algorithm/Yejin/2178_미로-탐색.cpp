#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int row, col;
int dist[101][101], maze[101][101];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void bfs(){
    queue<pair<int, int>> q;
    fill(dist[0], dist[101], INT_MAX);
    q.push({0, 0});
    dist[0][0] = 1;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if(nextY <0 || nextX < 0 | nextY >= row || nextX >= col) continue;
            if(dist[nextY][nextX] <= dist[currY][currX] + 1 || !maze[nextY][nextX]) continue;

            dist[nextY][nextX] = dist[currY][currX] + 1;
            q.push({nextY, nextX});
        }
    }
}

int main(){
    cin >> row >> col;
    for(int i = 0; i< row ; i++){
        string str;
        cin >> str;
        for(int j = 0; j < col; j++){
            maze[i][j] = str[j] - '0';
        }
    }

    bfs();

    cout << dist[row-1][col-1] << "\n";


}

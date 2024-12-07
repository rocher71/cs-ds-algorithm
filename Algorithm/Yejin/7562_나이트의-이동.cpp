#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int tc, n, startY, startX, endY, endX;
int dist[301][301];
//bool visit[301][301];
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2},
    dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(){
    fill(dist[0], dist[n], 0);
    queue<pair<int, int>> q;
    q.push({startY, startX});
//    visit[startY][startX] = true;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        if(currY == endY && currX == endX){
            cout << dist[currY][currX] << "\n";
            return;
        }

        for(int i = 0; i<8; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
            if(dist[nextY][nextX] != 0 && dist[nextY][nextX] <= dist[currY][currX] + 1) continue;

            dist[nextY][nextX] = dist[currY][currX] + 1;
            q.push({nextY, nextX});
        }
    }
}

int main(){
    cin >> tc;
    while(tc--){
        cin >> n >> startY >> startX >> endY >> endX;
        bfs();
    }
}

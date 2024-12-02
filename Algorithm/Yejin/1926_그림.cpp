#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int row, col, paintCnt, maxPaintArea;
int paper[501][501];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};
int visit[501][501];

void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = true;
    paintCnt++;
    int currPaintArea = 0;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        currPaintArea++;
        maxPaintArea = max(maxPaintArea, currPaintArea);
//        cout << currY << " " << currX << " " << currPaintArea << "\n";

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if(nextY <0 || nextX <0 || nextY >= row || nextX >= col || visit[nextY][nextX] || !paper[nextY][nextX]) continue;

            visit[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
}


int main(){
    cin >> row >> col;
    for(int i = 0; i< row; i++){
        for(int j = 0; j< col ; j++){
            cin >> paper[i][j];
        }
    }


    for(int i = 0 ; i< row; i++){
        for(int j = 0; j < col ; j++){
            if(visit[i][j] || !paper[i][j]) continue;
            bfs(i, j);
        }
    }

    cout << paintCnt << "\n" << maxPaintArea << "\n";

}

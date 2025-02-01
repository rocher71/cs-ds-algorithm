#include <iostream>
#include <queue>
using namespace std;

int row, col;
int mapArr[52][52], visit[52][52];
int dy[8] = {0, 0, -1, 1, -1, -1, 1, 1},
    dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = true;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 8; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
            if(!mapArr[nextY][nextX]) continue;
            if(visit[nextY][nextX]) continue;


            q.push({nextY, nextX});
            visit[nextY][nextX] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> col >> row;
    while(!(row == 0 && col == 0)){
        fill(&mapArr[0][0], &mapArr[row-1][col], 0);
        fill(&visit[0][0], &visit[row-1][col], 0);

        for(int i = 0; i< row; i++){
            for(int j = 0; j< col; j++){
                cin >> mapArr[i][j];
            }
        }

        int cnt = 0;
        for(int i = 0; i< row; i++){
            for(int j = 0; j< col; j++){
                if(visit[i][j] || !mapArr[i][j]) continue;
                bfs(i, j);
                cnt++;
            }
        }

        cout << cnt << "\n";

        cin >> col >> row;
    }

}

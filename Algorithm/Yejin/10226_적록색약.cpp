#include <iostream>
#include <queue>
using namespace std;

// R == 1, G == 2, B == 3
int n, normalCnt, weakCnt;
int colors[101][101], dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};
bool visitNormal[101][101], visitWeak[101][101];

void bfs(int startY, int startX, bool isWeak){
    queue<pair<int, int>> q;
    q.push({startY, startX});
    char color = colors[startY][startX];

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY <0 || nextX < 0 || nextY >= n || nextX >= n) continue;
            if(isWeak && visitWeak[nextY][nextX]) continue;
            if(!isWeak && (visitNormal[nextY][nextX] || colors[nextY][nextX] != color)) continue;

            if(isWeak && (color == 1 || color == 2) && !(colors[nextY][nextX] == 1 || colors[nextY][nextX] == 2)) continue;
            if(isWeak && color == 3 && colors[nextY][nextX] != 3) continue;

            q.push({nextY, nextX});
            if(isWeak) visitWeak[nextY][nextX] = true;
            else visitNormal[nextY][nextX] = true;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i< n; i++){
        string str;
        cin >> str;
        for(int j = 0; j< n; j++){
            if(str[j] == 'R') colors[i][j] = 1;
            else if(str[j] == 'G') colors[i][j] = 2;
            else if(str[j] == 'B') colors[i][j] = 3;
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j< n; j++){
            if(visitNormal[i][j]) continue;
            bfs(i, j, false);
            normalCnt++;
        }
    }

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j< n; j++){
            if(visitWeak[i][j]) continue;
            bfs(i, j, true);
            weakCnt++;
        }
    }

    cout << normalCnt << " " << weakCnt << "\n";
}

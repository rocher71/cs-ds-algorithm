#include<vector>
#include<queue>
#include<climits>
using namespace std;

int arr[101][101], dist[101][101];
int row, col;
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void bfs(){
    fill(&dist[0][0], &dist[row-1][col], INT_MAX);
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();
        
        if(currY == row - 1 && currX == col - 1) return;
        
        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            
            if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
            if(dist[nextY][nextX] <= dist[currY][currX] + 1) continue;
            if(arr[nextY][nextX] == 0) continue;
            
            dist[nextY][nextX] = dist[currY][currX] + 1;
            q.push({nextY, nextX});
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    row = maps.size();
    col = maps[0].size();
    
    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = maps[i][j];
        }
    }
    
    bfs();
    if(dist[row-1][col-1] == INT_MAX) return -1;
    return dist[row-1][col - 1];
}
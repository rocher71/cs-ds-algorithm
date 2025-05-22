#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#define MAX 51
using namespace std;

int n;
int arr[MAX][MAX], cnt[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void bfs(){
    queue<pair<int, int>> q;
    visit[0][0] = true;
    q.push({0, 0});

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
            int isBreak = arr[nextY][nextX] == 0 ? 1 : 0;
            if(visit[nextY][nextX] && cnt[nextY][nextX] <= cnt[currY][currX] + isBreak) continue;

            cnt[nextY][nextX] = cnt[currY][currX] + isBreak;
            visit[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0;i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            arr[i][j] = str[j] - '0';
        }
    }
    cnt[0][0] = arr[0][0] == 0 ? 1 : 0;

    bfs();

    cout << cnt[n-1][n-1] << "\n";
}
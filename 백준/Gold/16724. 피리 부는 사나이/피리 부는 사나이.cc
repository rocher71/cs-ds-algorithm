#include<iostream>
#include<algorithm>
#include<string>
#define MAX 1001
using namespace std;

int row, col, cnt;
int arr[MAX][MAX];
int visit[MAX][MAX];
int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

int dfs(int y, int x, int num) {
    visit[y][x] = num;

    int dir = arr[y][x];
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (ny < 0 || nx < 0 || ny >= row || nx >= col) return 0;
    if (visit[ny][nx] == num) return 0;
    if (visit[ny][nx] != 0) return visit[ny][nx];
    int isConn = dfs(ny, nx, num);
    if (isConn != 0) visit[y][x] = isConn;

    return isConn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < col; j++) {
            if (str[j] == 'U') arr[i][j] = 0;
            else if (str[j] == 'D') arr[i][j] = 1;
            else if (str[j] == 'L') arr[i][j] = 2;
            else if (str[j] == 'R') arr[i][j] = 3;
        }
    }

    int cnt = 0, num = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visit[i][j]) continue;
            int isConn = dfs(i, j, num++);
            if (isConn == 0) cnt++;
        }
    }
    
    cout << cnt << "\n";
}
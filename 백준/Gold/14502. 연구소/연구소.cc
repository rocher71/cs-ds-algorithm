#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#define MAX 9
using namespace std;

int n, m, blankCnt, maxAreaCnt = INT_MIN;
int arr[MAX][MAX], bfsArr[MAX][MAX], selectArr[3];
bool visit[MAX][MAX], permVisit[64];
vector<pair<int, int>> blanks, virus;
int dy[4] = {0, 0, -1, 1}, dx[4]  = {-1, 1, 0, 0};

void preSet(){
    fill(&visit[0][0], &visit[n-1][m], false);
    // bfsArr에 본래 arr 복사
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            bfsArr[i][j] = arr[i][j];
        }
    }

    // 선택된 세 좌표들 벽 처리
    for(int i = 0; i < 3; i++){
        int y = blanks[selectArr[i]].first;
        int x = blanks[selectArr[i]].second;
        bfsArr[y][x] = 1;
    }
}

// 이번 bfs에서의 안전영역 크기 계산
void postSet(){
    int cnt = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            if(bfsArr[i][j] == 0) cnt++;
        }
    }
    maxAreaCnt = max(cnt, maxAreaCnt);
}

void bfs(){
    queue<pair<int, int>> q;
    for(auto ij : virus){
        q.push(ij);
        visit[ij.first][ij.second] = true;
    }

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i< 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];
            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= m) continue;
            if(bfsArr[nextY][nextX] != 0 || visit[nextY][nextX]) continue;

            q.push({nextY, nextX});
            visit[nextY][nextX] = true;
            bfsArr[nextY][nextX] = 2;
        }
    }

}

void perm(int idx){
    if(idx == 3){
//        for(int i = 0; i< 3; i++) cout << selectArr[i] << " ";
//         cout << "\n";
        preSet(); // 전처리
        bfs();
//        for(int i = 0; i< n; i++){
//            for(int j = 0; j < m; j++){
//                cout << bfsArr[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        postSet(); // 후처리
        return;
    }
    for(int i = 0; i< blankCnt; i++){
        if(permVisit[i]) continue;
        if(idx != 0 && i <= selectArr[idx-1]) continue;
        permVisit[i] = true;
        selectArr[idx] = i;
        perm(idx + 1);
        permVisit[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) virus.push_back({i, j});
            if(arr[i][j] != 0) continue;
            // 빈 칸의 좌표들 모으기
            blanks.push_back({i, j});
            blankCnt++;
        }
    }

    perm(0);

    cout << maxAreaCnt << "\n";

}
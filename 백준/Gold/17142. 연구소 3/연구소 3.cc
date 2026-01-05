#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
#define WALL -1
#define VIRUS 2
using namespace std;

int n, m, blankCnt, minTime = INT_MAX, virusCnt;
int arr[51][51], dist[51][51];
int permVirus[10];
bool visitVirus[10];
vector<pair<int, int>> viruses;
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void bfs(){
    int currBlankCnt = blankCnt, currMinTime = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0;j < n; j++){
            if(dist[i][j] == -1) continue;
            dist[i][j] = INT_MAX;
        }
    }
    queue<pair<int, pair<int, int>>> q;
    for(int i = 0; i < m; i++){
        int y = viruses[permVirus[i]].first;
        int x = viruses[permVirus[i]].second;
        q.push({0, {y, x}});
        dist[y][x] = 0;
    }

    while(!q.empty()){
        int currTime = q.front().first;
        int currY = q.front().second.first;
        int currX = q.front().second.second;
        q.pop();

        if(currTime >= minTime) break;
        if(currTime != dist[currY][currX]) continue;
        if(currBlankCnt == 0) break;

        for(int i = 0; i < 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
            if(dist[nextY][nextX] == WALL || dist[nextY][nextX] <= currTime + 1) continue;

            // 처음 방문하는 빈 칸만 카운트 올리기
            if(dist[nextY][nextX] == INT_MAX && arr[nextY][nextX] == 0) currBlankCnt--;
//            if(currBlankCnt == 0) break;

            dist[nextY][nextX] = currTime + 1;
//            if(arr[nextY][nextX] == 2) q.push({dist[nextY][nextX] + 1, {nextY, nextX}});
//            else
            q.push({dist[nextY][nextX], {nextY, nextX}});
            currMinTime = max(currMinTime, dist[nextY][nextX]);
        }
    }

    if(currBlankCnt != 0) return;
//    cout << "\n";
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j<  n; j++){
//            if(dist[i][j] == -1) cout << "- ";
//            else if(dist[i][j] == INT_MAX) cout << "* ";
//            else cout << dist[i][j] << " ";
//        }
//        cout << "\n";
//    }
    minTime = min(minTime, currMinTime);
}

void comb(int idx, int num){
    if(idx == m){
        bfs();
        return;
    }
    for(int i = num; i < virusCnt; i++){
        if(visitVirus[i]) continue;
        visitVirus[i] = true;
        permVirus[idx] = i;
        comb(idx + 1, i + 1);
        visitVirus[i] = false;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) blankCnt++;
            else if(arr[i][j] == VIRUS) virusCnt++;
            else if(arr[i][j] == 1) dist[i][j] = WALL;
            if(arr[i][j] == VIRUS) viruses.push_back({i, j});
        }
    }

    if(blankCnt == 0){
        cout << "0\n";
        return 0;
    }

    comb(0, 0);

    if(minTime == INT_MAX) cout << "-1\n";
    else cout << minTime << "\n";

    return 0;

}
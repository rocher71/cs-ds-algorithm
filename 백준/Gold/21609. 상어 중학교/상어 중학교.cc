#include<iostream>
#include<deque>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#define BLANK -2
#define RAINBOW 0
#define BLACK -1
using namespace std;

int n, m, ans, turn;
queue<pair<int, int>> generals; // 일반 블록들 위치
int arr[21][21], visit[21][21];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void gravity(bool isSecond){
    deque<int> dq;
    for(int j = 0; j < n; j++){
        dq.push_back(arr[n - 1][j]);
        for(int i = n - 2; i >= 0; i--){
            int blankCnt = 0;
            if(arr[i][j] != BLANK && arr[i][j] != BLACK && !dq.empty()){
                while(!dq.empty() && dq.back() == BLANK){
                    dq.pop_back(); //empty 처리????
                    blankCnt++;
                }
            }
            dq.push_back(arr[i][j]);
            if(blankCnt ==0) continue;
            for(int k = 0; k < blankCnt; k++) dq.push_back(BLANK);
        }

        for(int i = n - 1; i >= 0; i--){
            if(dq.empty()){
                arr[i][j] = BLANK;
                continue;
            }
            arr[i][j] = dq.front();
            dq.pop_front();
            if(isSecond && arr[i][j] >= 1 && arr[i][j] <= m) generals.push({i, j});
        }
//        cout << "gravity 내부 " << j << "열 끝\n";
    }
}

void rotate(){
    int tmpArr[21][21];
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            tmpArr[n - j - 1][i] = arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = tmpArr[i][j];
        }
    }
    return;
}

pair<int, int> findGroups(){
    // {{크기, 무지개 블록 수}, {기준블록 y, {기준블록 x, {시작 y, 시작 x}}}}}
    priority_queue<pair<pair<int, int>, pair<int, pair<int, pair<int, int>>>>, vector<pair<pair<int, int>, pair<int, pair<int, pair<int, int>>>>>> pq;
    int groupCnt = 0;
    while(!generals.empty()){
        int startY = generals.front().first;
        int startX = generals.front().second;
        int curr = arr[startY][startX];
        generals.pop();
        turn++;
        if(visit[startY][startX] == turn) continue;

        int size = 1, rainbowCnt = 0, standardY = startY, standardX = startX;

        visit[startY][startX] = turn;
        groupCnt++;
        queue<pair<int, int>> q;
        q.push({startY, startX});
        while(!q.empty()){
            int currY = q.front().first;
            int currX = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nextY = currY + dy[i];
                int nextX = currX + dx[i];

                if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
                if(visit[nextY][nextX] == turn) continue;
                // 검정색(-1)이거나 무지개(0)가 아닌 일반 블록인데 내 번호와 다를 때
                if(arr[nextY][nextX] == BLACK || arr[nextY][nextX] == BLANK) continue;
                if(arr[nextY][nextX] != RAINBOW && arr[nextY][nextX] != curr) continue;

                visit[nextY][nextX] = turn;
                q.push({nextY, nextX});

                size++;
                if(arr[nextY][nextX] == RAINBOW){
                    rainbowCnt++;
                    continue;
                }

                if(nextY > standardY) continue;
                if(nextY == standardY){
                    if(nextX < standardX) standardX = nextX;
                    continue;
                }
                standardY = nextY;
                standardX = nextX;
            }
        }
        if(size < 2) continue;
        pq.push({{size, rainbowCnt}, {standardY, {standardX, {startY, startX}}}});
    }

    if(pq.empty()) return {-1, -1};
    return pq.top().second.second.second;
}

int removeGroup(int y, int x){
    turn++;
    int cnt = 0;
    int curr = arr[y][x];
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = turn;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i= 0; i < 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
            if(arr[nextY][nextX] == BLACK || arr[nextY][nextX] == BLANK) continue;
            if(arr[nextY][nextX] != RAINBOW && arr[nextY][nextX] != curr) continue;

            q.push({nextY, nextX});
            visit[nextY][nextX] = turn;
            arr[nextY][nextX] = BLANK;
            cnt++;
        }
    }
//    cout << "cnt : " << cnt<< "\n";
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] != RAINBOW && arr[i][j] != BLACK) generals.push({i, j});
        }
    }

    int turn = 1;
    pair<int, int> biggestGroup = findGroups();
    while(biggestGroup.first != -1){
//        cout << "Turn : " << turn << "\n";
        int cnt = removeGroup(biggestGroup.first, biggestGroup.second);
        ans += pow(cnt, 2);
//        cout << "After Remove Group" << "\n";
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++){
//                if(arr[i][j] == BLACK) cout << "* ";
//                else if(arr[i][j] == BLANK) cout << "- ";
//                else cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "ans : " << ans << "\n";

        gravity(false);
//        cout << "After gravity 1" << "\n";
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++){
//                if(arr[i][j] == BLACK) cout << "* ";
//                else if(arr[i][j] == BLANK) cout << "- ";
//                else cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        rotate();

//        cout << "After rotate" << "\n";
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++){
//                if(arr[i][j] == BLACK) cout << "* ";
//                else if(arr[i][j] == BLANK) cout << "- ";
//                else cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        gravity(true);

//        cout << "After gravity2" << "\n";
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++){
//                if(arr[i][j] == BLACK) cout << "* ";
//                else if(arr[i][j] == BLANK) cout << "- ";
//                else cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";

        biggestGroup = findGroups();
    }

    cout << ans << "\n";

}
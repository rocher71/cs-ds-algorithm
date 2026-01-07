#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int twoPow, q, n, l, totalSum;
int arr[65][65], newArr[65][65];
bool visit[65][65];
int dy[4] = {0, 0, -1, 1}, dx[4] = {-1, 1, 0, 0};

void rotate(int startY, int startX, int lPow){
    for(int i = startY; i < startY + lPow; i++){
        for(int j = startX; j < startX + lPow; j++){
            newArr[j - startX + startY][startX + startY + lPow - i - 1] = arr[i][j];
        }
    }
//    cout << startY << ", " << startX << "\n";
//    for(int j = 0; j < n; j++){
//        for(int k = 0; k < n; k++){
//            cout << newArr[j][k] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";
}

void subtractIce(){
    vector<pair<int, int>> toSubtract;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0) continue;
            // 모서리는 무조건 -1
//            if((i == 0 && j == 0)
//                || (i == 0 && j == n - 1)
//                || (i == n - 1 && j == 0)
//                || (i == n - 1 && j == n - 1)
//            ){
//               toSubtract.push_back({i, j});
//               continue;
//            }

            // 주변 네 개 확인
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int nextY = i + dy[k];
                int nextX = j + dx[k];

                if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
                if(arr[nextY][nextX] > 0) cnt++;
            }

            if(cnt >= 3) continue;

            toSubtract.push_back({i, j});
        }
    }
    for(int i = 0; i < toSubtract.size(); i++){
        arr[toSubtract[i].first][toSubtract[i].second]--;
        totalSum--;
    }
}

int bfs(int y, int x){
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    visit[y][x] = true;

    while(!q.empty()){
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        cnt++;

        for(int i = 0; i < 4; i++){
            int nextY = currY + dy[i];
            int nextX = currX + dx[i];

            if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
            if(visit[nextY][nextX] || arr[nextY][nextX] == 0) continue;

            visit[nextY][nextX] = true;
            q.push({nextY, nextX});
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> twoPow >> q;
    n = pow(2, twoPow);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            totalSum += arr[i][j];
        }
    }

    for(int i = 0; i < q; i++){
        cin >> l;
        int lPow = pow(2, l);
        if(l != 0){
            for(int j = 0 ; j < n; j += lPow){
                for(int k = 0; k < n; k += lPow){
                    rotate(j, k, lPow);
                }
            }
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    arr[j][k] = newArr[j][k];
                }
            }
        }
//        for(int j = 0; j < n; j++){
//            for(int k = 0; k < n; k++){
//                cout << arr[j][k] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        subtractIce();
    }

    if(totalSum == 0){
        cout << "0\n0\n";
        return 0;
    }

    int biggestIceCnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visit[i][j] || arr[i][j] == 0) continue;
            int cnt = bfs(i, j);
            biggestIceCnt = max(cnt, biggestIceCnt);
        }
    }

    cout << totalSum << "\n" << biggestIceCnt << "\n";
    return 0;
}
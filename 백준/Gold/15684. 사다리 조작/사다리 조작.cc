#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, h;
bool isBuilt[11][31][2]; // isBuilt[a][b][0] = true : 세로선 a의 높이 b, 왼쪽(a - 1)으로 가는 가로선이 있음

bool checkCanBuild(int left, int height){
    if(left == n) return false;

    // 해당 자리 혹은 왼쪽에 이미 있는 경우
    if(isBuilt[left][height][1] || isBuilt[left][height][0]) return false;

    if(left == n) return true;
    // 오른쪽에 이미 있는 경우
    if(isBuilt[left + 1][height][1]) return false;
    return true;
}

int returnDest(int num){
    int curr = num;
    for(int i = 1; i <= h; i++){
        bool left = isBuilt[curr][i][0];
        bool right = isBuilt[curr][i][1];

        if(!left && !right) continue;

        if(left) curr--;
        else curr++;
    }
    return curr;
}

bool checkAns(){
    for(int i = 1; i <= n ;i++){
        if(returnDest(i) != i) return false;
    }
    return true;
}

bool perm(int size, int idx){
    if(idx == size){
        bool isAns = checkAns();
        if(isAns) return true;
        return false;
    }
    for(int i = 1; i < n; i++){ // 세로선
        for(int j = 1; j <= h; j++){ // 높이
            if(!checkCanBuild(i,j)) continue;
            isBuilt[i][j][1] = true;
            isBuilt[i + 1][j][0] = true;
            if(perm(size, idx + 1)) return true;
            isBuilt[i][j][1] = false;
            isBuilt[i + 1][j][0] = false;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        isBuilt[b][a][1] = true; // b의 높이 a에 오른쪽으로 가는 가로선 존재
        if(b == n) continue; // 가장 오른쪽 세로선이면 continue
        isBuilt[b+1][a][0] = true; // b+1의 높이 a에 왼쪽으로 가는 가로선 존재
    }
    if(checkAns()){
        cout << "0\n";
        return 0;
    }

    int ans = -1;
    for(int i = 1; i <= 3; i++){
        if(!perm(i, 0)) continue;
        ans = i;
        break;
    }

    cout << ans << "\n";


}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
using namespace std;

int n, minDiff = INT_MAX;
int arr[20][20], teamPerm[20];

int getDiff(){
    int oneSum = 0, twoSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(teamPerm[i] != teamPerm[j]) continue;
            if(teamPerm[i] == 1) oneSum += arr[i][j] ; // i, j 모두 1팀
            else twoSum += arr[j][i]; // 2팀
        }
    }
//    for(int i = 0; i < n; i++) cout << teamPerm[i] << " ";
//    cout << "\nDiff : " << abs(oneSum - twoSum) << "\n";
    return abs(oneSum - twoSum);
}

void perm(int idx, int oneCnt, int twoCnt){
    if(idx == n){
        minDiff = min(minDiff, getDiff());
        return;
    }
    if(oneCnt == n / 2){
        teamPerm[idx] = 2;
        perm(idx + 1, oneCnt, twoCnt + 1);
        return;
    }
    if(twoCnt == n / 2){
        teamPerm[idx] = 1;
        perm(idx + 1, oneCnt + 1, twoCnt);
        return;
    }
    teamPerm[idx] = 1;
    perm(idx + 1, oneCnt + 1, twoCnt);
    teamPerm[idx] = 2;
    perm(idx + 1, oneCnt, twoCnt + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    perm(0, 0, 0);

    cout << minDiff << "\n";

}

/*
8
0 5 4 5 4 5 4 5
4 0 5 1 2 3 4 5
9 8 0 1 2 3 1 2
9 9 9 0 9 9 9 9
1 1 1 1 0 1 1 1
8 7 6 5 4 0 3 2
9 1 9 1 9 1 0 9
6 5 4 3 2 1 9 0
 */
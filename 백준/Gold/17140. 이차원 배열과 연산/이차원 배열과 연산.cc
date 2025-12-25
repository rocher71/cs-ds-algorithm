#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#define MAX 100
using namespace std;

unordered_map<int, int> numCnts;
int arr[MAX + 1][MAX + 1];
int r, c, k, rowCnt = 3, colCnt = 3;

int sortRow(int rowNum){
    vector<pair<int, int>> v; // {개수, 숫자}
    numCnts.clear();

    for(int i = 1; i <= colCnt; i++){
        if(arr[rowNum][i] == 0) continue;
        numCnts[arr[rowNum][i]]++;
    }

    for(auto numCnt : numCnts){
        v.push_back({numCnt.second, numCnt.first});
    }

    sort(v.begin(), v.end());
    fill_n(arr[rowNum], colCnt + 1, 0);

    int idx = 1;
    for(int i = 0; i < min((int)v.size(), 50); i++){ // 100 넘어갈 때 처리
        arr[rowNum][idx++] = v[i].second;
        arr[rowNum][idx++] = v[i].first;
    }
    int newColCnt = (int) v.size() * 2;
    return newColCnt;
}

int sortCol(int colNum){
    vector<pair<int, int>> v; // {개수, 숫자}
    numCnts.clear();

    for(int i = 1; i <= rowCnt; i++){
        if(arr[i][colNum] == 0) continue;
        numCnts[arr[i][colNum]]++;
    }

    for(auto numCnt : numCnts){
        v.push_back({numCnt.second, numCnt.first});
    }

    sort(v.begin(), v.end());
    for(int i = 1; i <= rowCnt; i++){
        arr[i][colNum] = 0;
    }

    int idx = 1;
    for(int i = 0; i < min((int)v.size(), 50); i++){
        arr[idx++][colNum] = v[i].second;
        arr[idx++][colNum] = v[i].first;
    }
    int newRowCnt = (int) v.size() * 2;
    return newRowCnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> k;
    for(int i =1 ; i<= 3; i++){
        for(int j = 1; j<= 3; j++){
            cin >> arr[i][j];
        }
    }

    if(arr[r][c] == k){
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    for(int time = 1; time <= MAX; time++){
        int newRowCnt = 0, newColCnt = 0;
        if(rowCnt >= colCnt) for(int i = 1; i <= rowCnt; i++) newColCnt = max(newColCnt, sortRow(i));
        else for(int i = 1; i <= colCnt; i++) newRowCnt = max(newRowCnt, sortCol(i));

        if(rowCnt >= colCnt) colCnt = newColCnt;
        else rowCnt = newRowCnt;

//        cout << "\ntime : " << time << "\n";
//        for(int i = 1; i <= rowCnt; i++){
//            for(int j = 1; j <= colCnt; j++){
//                cout << arr[i][j] << " ";
//            }
//            cout << "\n";
//        }
        if(arr[r][c] != k) continue;

        ans = time;
        break;
    }

    if(ans == 0) cout << "-1\n";
    else cout << ans << "\n";
}
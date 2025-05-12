#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
#define n 9
using namespace std;

bool solved = false;
int filledCnt = 0;
int arr[n][n];
bool existsX[n][n + 1], existsY[n][n + 1], existsInZone[n][n + 1];
vector<pair<int, int>> blanks;


void search(int idx) {
    if (solved) return;

    if (idx == blanks.size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        solved = true;
        return;
    }

    vector<int> posNums;
    
    int y = blanks[idx].first;
    int x = blanks[idx].second;
    int zone = (y / 3) * 3 + (x / 3);

    // 가로 세로 구역
    for (int i = 1; i <= n; i++) {
        if (!existsY[y][i] && !existsX[x][i] && !existsInZone[zone][i]) {
            posNums.push_back(i);
        }
    }

    for (int i = 0; i < posNums.size(); i++) {
        int num = posNums[i];

        arr[y][x] = num;
        existsX[x][num] = true;
        existsY[y][num] = true;
        existsInZone[zone][num] = true;

        search(idx + 1);
        //if (solved) return;

        existsX[x][num] = false;
        existsY[y][num] = false;
        existsInZone[zone][num] = false;
        filledCnt--;
       // arr[y][x] = 0;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                blanks.push_back({ i, j });
                continue;
            }
            
            // 해당 y, x열에 숫자 arr[i][j] 가 존재하는지
            existsY[i][arr[i][j]] = true;
            existsX[j][arr[i][j]] = true;

            int zone = (i / 3) * 3 + (j / 3);
            existsInZone[zone][arr[i][j]] = true;
        }
    }
    
    

    search(0);
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }*/

    return 0;
}
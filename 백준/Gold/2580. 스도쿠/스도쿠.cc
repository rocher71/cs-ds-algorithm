#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
#define n 10
using namespace std;

int filledCnt = 0;
int arr[n][n];
bool existsX[n][n], existsY[n][n], existsInZone[n][n];
vector<pair<int, int>> blanks;

int getZone(int y, int x) {
    if (y <= 3 && x <= 3) return 1;
    else if (y <= 3 && x <= 6) return 2;
    else if (y <= 3 && x <= 9) return 3;
    else if (y <= 6 && x <= 3) return 4;
    else if (y <= 6 && x <= 6) return 5;
    else if (y <= 6 && x <= 9) return 6;
    else if (y <= 9 && x <= 3) return 7;
    else if (y <= 9 && x <= 6) return 8;
    else if (y <= 9 && x <= 9) return 9;
}

void search(int y, int x, int idx) {
    vector<int> posNums;
    int zone = getZone(y, x);

    // 가로 세로 구역
    for (int i = 1; i < n; i++) {
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
        filledCnt++;

        if (filledCnt == blanks.size()) return;

        search(blanks[idx + 1].first, blanks[idx + 1].second, idx + 1);

        if (filledCnt == blanks.size()) return;
        existsX[x][num] = false;
        existsY[y][num] = false;
        existsInZone[zone][num] = false;
        filledCnt--;
        arr[y][x] = 0;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                blanks.push_back({ i, j });
                continue;
            }
            
            // 해당 y, x열에 숫자 arr[i][j] 가 존재하는지
            existsY[i][arr[i][j]] = true;
            existsX[j][arr[i][j]] = true;

            int zone = getZone(i, j);
            existsInZone[zone][arr[i][j]] = true;
        }
    }
    
    

    search(blanks[0].first, blanks[0].second, 0);


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
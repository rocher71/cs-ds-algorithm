#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define n 9
using namespace std;

bool solved;
int arr[n][n];
bool inY[n][10], inX[n][10], inZone[n][10];
vector<pair<int, int>> blanks;

void fillBlank(int idx) {
    if (solved) return;
    if (idx == blanks.size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j];
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

    for (int i = 1; i <= 9; i++) {
        if (!inY[y][i] && !inX[x][i] && !inZone[zone][i]) posNums.push_back(i);
    }

    for (int i = 0; i < posNums.size(); i++) {
        int num = posNums[i];
        arr[y][x] = num;
        inY[y][num] = inX[x][num] = inZone[zone][num] = true;

        fillBlank(idx + 1);
        if (solved) return; // 재귀 끝나고 돌아온 함수에서도 바로 리턴하도록

        // arr[y][x] = 0; 어차피 덮어씌일거라서 안넣어줘도 됨
        inY[y][num] = inX[x][num] = inZone[zone][num] = false;
    }
}

int main() {
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (i / 3) * 3 + (j / 3) << " ";
        }
        cout << "\n";
    }
    return 0;*/

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            int num = str[j] - '0';
            arr[i][j] = num;
            
            if (num == 0) {
                blanks.push_back({ i, j });
                continue;
            }

            int zone = (i / 3) * 3 + (j / 3);
            inY[i][num] = true;
            inX[j][num] = true;
            inZone[zone][num] = true;
        }
    }

    fillBlank(0);

    return 0;
    
}
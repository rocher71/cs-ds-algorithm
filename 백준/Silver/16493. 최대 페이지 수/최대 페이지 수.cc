#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int days[201], page[201];
int maxPage[201][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> days[i];
        cin >> page[i];
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(days[i] <= j) maxPage[i][j] = max(maxPage[i-1][j], maxPage[i-1][j - days[i]] + page[i]);
            else maxPage[i][j] = maxPage[i-1][j];
        }
    }

    cout << maxPage[m][n] << "\n";
}
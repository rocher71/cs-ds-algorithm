#include <iostream>
#include <algorithm>
using namespace std;

int row, col, k;
int arr[302][302], sum[302][302];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> row >> col;
    for(int i = 1 ; i<= row; i++){
        for(int j =1; j <= col; j++){
            cin >> arr[i][j];

            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }

    cin >> k;
    for(int i = 0; i< k; i++){
        int fromY, fromX, toY, toX;
        cin >> fromY >> fromX>>toY>>toX;
        cout << sum[toY][toX] - sum[toY][fromX-1] - sum[fromY-1][toX] + sum[fromY-1][fromX-1] << "\n";
    }
}
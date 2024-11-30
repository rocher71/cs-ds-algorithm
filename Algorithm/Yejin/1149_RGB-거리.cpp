#include <iostream>
using namespace std;

// 0 : R, 1 : G, 2 : B
int cost[1001][3], dp[1001][3];
int n;

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j < 3; j++){
            cin >> cost[i][j];
        }
    }

    for(int i = 0; i < 3; i++) dp[1][i] = cost[1][i];

    for(int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << "\n";
}

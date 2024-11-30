#include <iostream>
using namespace std;

int n;
int dp[301][3], stairs[301];
// dp[i][j] : 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라갔을 때 최대값, 이때 i는 무조건 밟아야함.

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> stairs[i];

    dp[1][1] = stairs[1];
    dp[2][1] = stairs[2];
    dp[2][2] = stairs[1] + stairs[2];

    for(int i = 3; i<= n; i++){
        dp[i][1] = max(dp[i - 2][1], dp[i-2][2]) + stairs[i];
        dp[i][2] = dp[i-1][1] + stairs[i];
    }

    cout << max(dp[n][1], dp[n][2]) << "\n";
}

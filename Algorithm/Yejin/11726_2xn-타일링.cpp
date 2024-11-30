#include <iostream>
using namespace std;

int dp[1001];
int n;

int main(){
    cin >>  n;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i<= n; i++){
        dp[i] = (dp[i-1] + dp[i-2] ) % 10007;
    }
    // 아래는 나누기는 없어도 되는데 위에는 있어야 정답 처리
    cout << dp[n] % 10007 << "\n";
}

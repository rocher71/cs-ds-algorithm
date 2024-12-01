#include <iostream>
using namespace std;

int tc;
int dp[41][2];

int main(){
    dp[0][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= 40; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }


    cin >> tc;
    while(tc--){
        int num;
        cin >> num;

        cout << dp[num][0] << " " << dp[num][1] << "\n";
    }
}

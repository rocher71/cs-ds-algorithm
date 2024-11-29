#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];
 
int main(){
    cin >> n;

    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i<= n; i++){
        int minNum = dp[i-1];
        if(i % 3 == 0) minNum = min(minNum, dp[i / 3]);
        if(i % 2 == 0) minNum = min(minNum, dp[i / 2]);

        dp[i] = minNum + 1;
    }

    cout << dp[n] << "\n";
}

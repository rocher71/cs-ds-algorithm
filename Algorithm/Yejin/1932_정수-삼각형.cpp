#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> triangle[501];
int dp[501][501];

int main(){
    cin >> n;

    for(int i = 1; i<= n; i++){
        for(int j = 0; j< i ; j++){
            int n;
            cin >> n;
            triangle[i].push_back(n);
        }
    }

    //cout << triangle[0][0];

    dp[1][0] = triangle[1][0];

    for(int i = 2; i<= n; i++){
        for(int j = 0; j< i; j++){
            int num = triangle[i][j];
            int leftParent = j >= 1 ?  dp[i-1][j-1] : 0;
            int rightParent = j == i - 1 ? 0 : dp[i-1][j];

            dp[i][j] = num + max(leftParent, rightParent);
        }
    }

    sort(dp[n], dp[n] + n);

    cout << dp[n][n-1] << "\n";


}

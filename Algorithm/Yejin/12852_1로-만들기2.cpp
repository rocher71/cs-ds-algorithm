#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n;
int dp[1000001], dpPath[1000001];
vector<int> path;

int main(){
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    dpPath[1] = 0; // 1을 1로 만드는 횟수는 0임!
    dpPath[2] = 1;
    dpPath[3] = 1;

    for(int i = 4; i<= n; i++){
        int three = (i % 3 == 0) ? dp[i/3] + 1 : INT_MAX;
        int two = (i % 2 == 0) ? dp[i/2] + 1 : INT_MAX;
        int least = min(dp[i-1] + 1, min(three, two));
        dp[i] = least;
        if(least == dp[i-1] + 1){
            dpPath[i] = i-1;
            continue;
        }
        if(least == three){
            dpPath[i] = i / 3;
            continue;
        }
        dpPath[i] = i/2;
    }

    int currPath = n;
    path.push_back(n);
    while(currPath != 1){
        path.push_back(dpPath[currPath]);
        currPath = dpPath[currPath];
    }

    cout << dp[n] << "\n";
    for(int i : path) cout << i << " ";
    cout << "\n";
}

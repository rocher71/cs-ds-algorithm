#include <iostream>
using namespace std;

int n;
long long arr[91], dp[91];

int main(){
    cin >> n;
    arr[1] = 1;
    arr[2] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        arr[i] = dp[i - 2] + 1;
        dp[i] = arr[i] + dp[i - 1];
    }

    cout << arr[n] <<"\n";
}

#include <iostream>
using namespace std;

int n;
int arr[1001], dp[1001];

int main(){
    cin >> n;

    dp[1] = 1;
    arr[1] = 1;
    arr[2] = 3;
    dp[2] = 4;

    for(int i = 3; i<= n; i++){
        arr[i] = dp[i-1];
        if(i % 2 == 0) arr[i] += 2;
        else arr[i]++;
        dp[i] = (dp[i-1] + arr[i]) % 10007;
    }

    cout << arr[n] << "\n";
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
vector<int> numbers;
int dp[11];
int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    cin >> tc;
    for(int i = 0; i< tc; i++){
        int num;
        cin >> num;
        numbers.push_back(num);

        for(int i = 4; i<= num; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[num] << "\n";

    }


}

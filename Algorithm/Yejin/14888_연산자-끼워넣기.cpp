#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int numbers[11], oper[4], maxNum = INT_MIN, minNum = INT_MAX;

//백트래킹
void solve(int curr, int idx){
    if(idx == n){
        maxNum = max(maxNum, curr);
        minNum = min(minNum, curr);
        return;
    }

    for(int i = 0; i<4; i++){
        if(oper[i] <= 0) continue;
        oper[i]--;
        if(i == 0) solve(curr + numbers[idx], idx+1);
        else if(i == 1) solve(curr - numbers[idx], idx+1);
        else if(i == 2) solve(curr * numbers[idx], idx+1);
        else if(i == 3) solve(curr / numbers[idx], idx+1);
        oper[i]++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++) cin >> numbers[i];
    for(int i = 0; i<4; i++) cin >> oper[i];

    solve(numbers[0], 1);

    cout << maxNum << "\n" << minNum <<"\n";
}

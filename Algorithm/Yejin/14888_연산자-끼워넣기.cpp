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
        oper[i]--; // 현재 연산자로 쭉 더 연산할것이므로 개수 --
        if(i == 0) solve(curr + numbers[idx], idx+1); // 덧셈
        else if(i == 1) solve(curr - numbers[idx], idx+1); // 뺄셈
        else if(i == 2) solve(curr * numbers[idx], idx+1); // 곱셈
        else if(i == 3) solve(curr / numbers[idx], idx+1); // 나눗셈
        oper[i]++; //현재 연산자는 다 돌고 나온 뒤이기때문에 다시 추가해줌
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++) cin >> numbers[i];
    for(int i = 0; i<4; i++) cin >> oper[i];

    solve(numbers[0], 1);

    cout << maxNum << "\n" << minNum <<"\n";
}

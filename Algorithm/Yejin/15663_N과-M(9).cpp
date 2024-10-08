// 백트래킹
#include <iostream>
#include <algorithm>
using namespace std;

int numbers[8], ans[8], n, m;
bool visit[8];

void solve(int idx){
    if(idx == m){
        for(int i = 0; i<m; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    // 같은 idx에서 이전에 넣었던 숫자와 겹치지 않도록 함.
    int lastNum = -1;
    for(int i = 0; i<n; i++){
        if(visit[i] || (numbers[i] == lastNum)) continue;
        ans[idx] = numbers[i];
        visit[i] = true;
        lastNum = numbers[i];
        solve(idx+1);
        visit[i] = false;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i< n; i++) cin >> numbers[i];
    sort(numbers, numbers+n);
    solve(0);
}

// 백트래킹
#include <iostream>
#define INF 1e9
using namespace std;

int numbers[20], n, s, ans;

// 각 숫자를 더하는 경우, 안 더하는 경우 두 가지로 분기해서 전체 백트래킹
void solve(int curr, int idx){
    if(idx == n){
        if(curr == s) ans++;
        return;
    }
    solve(curr, idx+1); // 현재 index 숫자 추가 안하고 재귀
    if(curr == INF) curr = 0;
    solve(curr + numbers[idx], idx+1); // 현재 index 숫자 추가 하고 재귀
}

int main(){
    cin >> n >> s;
    for(int i = 0; i<n; i++) cin >> numbers[i];

    // 처음 호출 할 때 curr에 0을 넣을 시, 찾는 값 즉 s가 0일 때 구분할 수 없음, 따라서 범위 외 값인 Inf 입력
    solve(INF, 0);
    cout << ans << "\n";
}

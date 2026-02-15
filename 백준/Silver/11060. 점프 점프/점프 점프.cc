#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n;
int arr[1001];
bool visit[1001];

int bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0] = true;

    while(!q.empty()){
        int idx = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(idx == n - 1) return cnt;

        int num = arr[idx];
        for(int i = 1; i <= num; i++){
            int next = idx + i;
            if(visit[next] || next >= n) continue;
            q.push({next, cnt + 1});
            visit[next] = true;
        }

    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n;i++) cin >> arr[i];

    int ans = bfs();

    cout << ans << "\n";
}
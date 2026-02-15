#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

long long a, b;

long long bfs(){
    queue<pair<long long, long long>> q;
    q.push({a, 1});

    while(!q.empty()){
        long long curr = q.front().first;
        long long stage = q.front().second;
        q.pop();

//        cout << stage << " " << curr << "\n";

        if(curr == b) return stage;

        if(curr * 2 <= b) q.push({curr * 2, stage + 1});
        if(curr * 10 + 1 <= b) q.push({curr * 10 + 1, stage + 1});
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b;

    long long ans = bfs();
    cout << ans << "\n";
}
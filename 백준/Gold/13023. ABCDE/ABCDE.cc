#include<iostream>
#include<vector>
using namespace std;

int n, m, ans =0;
vector<int> v[2001];
bool visit[2001];

void dfs(int curr, int cnt){
    visit[curr] = true;
    if(cnt == 4){
        ans = 1;
        return;
    }
    for(int i = 0; i < v[curr].size(); i++){
        int next = v[curr][i];
//        if(cnt == 3){
//            ans = 1;
//            return;
//        }
        if(visit[next]) continue;
        dfs(next, cnt + 1);
        visit[next] = false;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i< n; i++){
        if(ans == 1) break;
        fill_n(visit, n, 0);
        dfs(i, 0);
    }
    dfs(0, 0);
    cout <<  ans << "\n";

}
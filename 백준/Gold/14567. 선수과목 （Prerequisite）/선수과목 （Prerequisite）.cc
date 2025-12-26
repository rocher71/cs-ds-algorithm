#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<int> g[1001];
int indeg[1001], ans[1001];

void topology(){
    queue<int> q;
    for(int i = 1;i <= n; i++){
        if(indeg[i] != 0) continue;
        q.push(i);
        ans[i] = 1;
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < g[curr].size(); i++){
            int next = g[curr][i];
            if(--indeg[next] != 0) continue;
            q.push(next);
            ans[next] = ans[curr] + 1;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    topology();

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";

}
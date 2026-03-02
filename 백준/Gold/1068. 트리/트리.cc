#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define VISITED 1
#define DELETED 2
using namespace std;

int n;
int visit[51];
vector<int> graph[51];

int bfs(int a){
    int cnt = 0;
    if(visit[a] == DELETED) return 0;
    queue<int> q;
    q.push(a);
    visit[a] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        bool hasNoKids = true;
        for(int i = 0; i < graph[curr].size(); i++){
            int next = graph[curr][i];

            if(visit[next] == DELETED) continue;

            hasNoKids = false;
            if(visit[next] == VISITED) continue;
            visit[next] = VISITED;
            q.push(next);
        }
        if(hasNoKids) cnt++;
    }
    return cnt;
}

void deleteBfs(int a){
    queue<int> q;
    q.push(a);
    visit[a] = DELETED;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i];
            if(visit[next]) continue;
            visit[next] = DELETED;
            q.push(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int root, toDelete;
    cin >> n;
    for(int i = 0; i< n; i++){
        int par;
        cin >> par;
        if(par == -1) root = i;
        else graph[par].push_back(i);
    }

    cin >> toDelete;

    deleteBfs(toDelete);
    int ans = bfs(root);

    cout << ans << "\n";
}
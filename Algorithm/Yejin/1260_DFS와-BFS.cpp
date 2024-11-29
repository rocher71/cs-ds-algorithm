#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, v;
vector<int> graph[1001];
bool bfsVisit[1001], dfsVisit[1001];

void dfs(int curr){
    dfsVisit[curr] = true;
    cout << curr << " ";

    for(int i = 0; i < graph[curr].size(); i++){
        int nxt = graph[curr][i];
        if(dfsVisit[nxt]) continue;
        dfs(nxt);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    bfsVisit[start] = true;

    while(!q.empty()) {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (int i = 0; i < graph[curr].size(); i++) {
            int nxt = graph[curr][i];
            if (bfsVisit[nxt]) continue;
            bfsVisit[nxt] = true;
            q.push(nxt);
        }
    }
}

int main(){
    cin >> n >> m >>v;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i<= n; i++) sort(graph[i].begin(), graph[i].end());

    dfs(v);
    cout << "\n";
    bfs(v);
    cout << "\n";
}

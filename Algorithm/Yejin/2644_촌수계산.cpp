#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, toFindFirst, toFindSecond;
vector<int> v[101];
bool visit[101];

int bfs(){
    queue<pair<int, int>> q; // {사람 번호, 촌수}
    q.push({toFindFirst, 0});
    visit[toFindFirst] = true;

    while(!q.empty()){
        int curr = q.front().first;
        int currChon = q.front().second;
        q.pop();

        if(curr == toFindSecond) return currChon;

        for(int i = 0; i< v[curr].size(); i++){
            int next = v[curr][i];
            if(visit[next]) continue;
            q.push({next, currChon + 1});
            visit[next] = true;
        }
    }

    return -1;
}

int main(){
    cin >> n >> toFindFirst >> toFindSecond >> m;

    for(int i = 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = bfs();


    cout << ans << "\n";

    return 0;
}

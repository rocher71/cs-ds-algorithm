#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n;
bool hasRoute[101][101];
int visit[101];
vector<int> g[101];

void bfs(int num){
    queue<int> q;
    q.push(num);
//    visit[num] = num;
    bool isFirst = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(!isFirst) hasRoute[num][curr] = true;
        isFirst = false;

        for(int i = 0; i < g[curr].size(); i++){
            int next = g[curr][i];

            if(visit[next] == num) continue;

            q.push(next);
            visit[next] = num;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a;
            cin >> a;
            if(a == 0) continue;
            g[i].push_back(j);
        }
    }

    for(int i = 1; i <= n; i++) bfs(i);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << hasRoute[i][j] << " ";
        }
        cout << "\n";
    }

}
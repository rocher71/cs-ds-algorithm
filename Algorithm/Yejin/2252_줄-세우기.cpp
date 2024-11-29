#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> students[32001];
int deg[32001];
vector<int> ans;

void topological(){
    queue<int> q;
    for(int i = 1; i<= n; i++) if(deg[i] == 0) q.push(i);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for(int i = 0; i < students[curr].size(); i++){
            int next = students[curr][i];
            deg[next]--;
            if(deg[next] == 0) q.push(next);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        students[a].push_back(b);
    }

    for(int i = 1; i<= n; i++){
        for(int j = 0; j< students[i].size(); j++){
            deg[students[i][j]]++;
        }
    }

    topological();

    for(int i : ans) cout << i << " ";
    cout << "\n";




}

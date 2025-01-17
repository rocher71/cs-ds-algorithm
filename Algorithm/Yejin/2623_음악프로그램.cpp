#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int deg[1001];
vector<int> v[1001];
vector<int> ans;

void topology(){
    queue<int> q;

    for(int i = 1; i<= n; i++) if(deg[i] == 0) q.push(i);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for(int i = 0; i< v[curr].size(); i++){
            int next = v[curr][i];
            deg[next]--;
            if(deg[next] == 0) q.push(next);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i< m; i++){
        int cnt;
        cin >> cnt;
        vector<int> singers(cnt);
        for(int j = 0; j < cnt ; j++) cin >> singers[j];

        if(cnt <= 1) continue;
        for(int j = 1; j < cnt; j++){
            v[singers[j-1]].push_back(singers[j]);
        }
    }

    for(int i = 1; i<= n ;i++){
        for(int j = 0; j< v[i].size(); j++){
            deg[v[i][j]]++;
        }
    }

    topology();

    if(ans.size() != n){
        cout << "0\n";
        return 0;
    }

    for(int i : ans) cout << i <<"\n";
    return 0;
}

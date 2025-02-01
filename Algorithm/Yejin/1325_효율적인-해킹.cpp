#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[10001];
int cnt[10001];
bool visit[10001];

void bfs(int num){
    //fill_n(cnt, n + 1, 0);
    fill_n(visit, n + 1, 0);
    queue<int> q; //curr, prev
    q.push(num);
    visit[num] = true;

    int currCnt = -1;
    while(!q.empty()){
        int curr = q.front();
        currCnt++;
        q.pop();

        for(int i = 0; i< v[curr].size(); i++){
            int next = v[curr][i];
            if(visit[next]) continue;
            q.push(next);
            visit[next] = true;
        }
    }
    cnt[num] = currCnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >>m;
    for(int i = 0; i< m; i++){
        int a, b;
        cin >> a >>b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(cnt[i]) continue;
        bfs(i);
    }

    //for(int i = 1; i<= n; i++) cout << cnt[i] << "\n";
    vector<pair<int, int>> ans;
    for(int i = 1; i<=n ;i++){
        ans.push_back({cnt[i], i});
    }

    sort(ans.begin(), ans.end());

//    for(auto i : ans){
//        cout << i.first << " " << i.second << "\n";
//    }

    int maxCnt = ans[n-1].first, idx = n - 1;
    while(true){
        if(idx - 1 >= 0 && ans[idx-1].first == maxCnt){
            idx--;
            continue;
        }
        break;
    }

    for(int i = idx; i<= n - 1; i++){
        cout << ans[i].second << "\n";
    }
}

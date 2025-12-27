#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int n, m;
int indeg[101], neededCnt[101];
vector<pair<int, int>> g[101]; // g[a] = {b, c} : a 를 만드는데 b가 c개 필요함
vector<int> topologyGraph[101];
deque<int> topologyResult;
bool isBase[101];

void topology(){
    queue<int> q;
    for(int i = 1; i<= n; i++) if(indeg[i] == 0) q.push(i);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        topologyResult.push_back(curr);

        for(int i = 0; i< topologyGraph[curr].size(); i++){
            int next = topologyGraph[curr][i];
            indeg[next]--;
            if(indeg[next] == 0) q.push(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        indeg[a]++;
        topologyGraph[b].push_back(a);
    }
    for(int i = 1; i<= n; i++) if(indeg[i] == 0) isBase[i] = true;

    topology();

    neededCnt[n] = 1;

    while(!topologyResult.empty()){
        int curr = topologyResult.back();
        topologyResult.pop_back();
        int currCnt = neededCnt[curr];

        for(int i = 0; i< g[curr].size(); i++){
            int next = g[curr][i].first;
            int nextCnt = g[curr][i].second;

            neededCnt[next] += currCnt * nextCnt;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!isBase[i]) continue;
        cout << i << " " << neededCnt[i] << "\n";
    }
}
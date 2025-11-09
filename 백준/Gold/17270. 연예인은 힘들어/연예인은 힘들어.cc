#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;

int v, m, aLoc, bLoc;
vector<pair<int, int>> graph[101];
int aDist[101], bDist[101], distSum[101];

void dijk(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    bool isA = start == aLoc;

    while(!pq.empty()){
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(int i = 0; i< graph[curr].size(); i++){
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;

            if(isA && aDist[next] <= cost + nextCost) continue;
            if(!isA && bDist[next] <= cost + nextCost) continue;

            pq.push({cost + nextCost, next});
            if(isA) aDist[next] = cost + nextCost;
            else bDist[next] = cost + nextCost;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> v >> m;
    for(int i = 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> aLoc >> bLoc;

    fill_n(aDist, v + 1, INT_MAX);
    fill_n(bDist, v+1, INT_MAX);

    dijk(aLoc);
    dijk(bLoc);

    int minDist = INT_MAX;
    vector<int> ansList;
    for(int i = 1; i <= v; i++){
        distSum[i] = aDist[i] + bDist[i];
        if(i == aLoc || i == bLoc) continue;
        minDist = min(minDist, distSum[i]);
    }
    for(int i = 1; i<= v; i++){
        if(minDist == distSum[i]) ansList.push_back(i);
    }

    vector<int> ansListB;
    int minADist = INT_MAX;
    for(int i : ansList){
        if(aDist[i] > bDist[i]) continue;
        ansListB.push_back(i);
        minADist = min(minADist, aDist[i]);
    }

    int ans = -1;
    if(minADist == INT_MAX){
        cout << ans << "\n";
        return 0;
    }
    for(int i : ansListB){
        if(minADist != aDist[i]) continue;
        ans = i;
        break;
    }

    cout << ans << "\n";



}
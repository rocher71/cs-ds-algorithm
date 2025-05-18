#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#define MAX 100001
using namespace std;

int n, e, from, to;
int maxWeight[MAX];
vector<pair<int, int>> v[MAX];

void dijk(){
    priority_queue<pair<int, int>> pq;
    pq.push({0, from});
    maxWeight[from] = 0;

    while(!pq.empty()){
        int currWeight = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(maxWeight[curr] != currWeight) continue;
        if(curr == to) return;

        for(int i = 0; i< v[curr].size(); i++){
            int next = v[curr][i].first;
            int nextWeight = curr == from ? v[curr][i].second : min(v[curr][i].second, currWeight);

            if(maxWeight[next] >= nextWeight) continue;

            maxWeight[next] = nextWeight;
            pq.push({maxWeight[next], next});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int a, b, weight;
        cin >> a >> b >> weight;
        v[a].push_back({b, weight});
        v[b].push_back({a, weight});
    }
    cin >> from >> to;

    dijk();

    cout << maxWeight[to] << "\n";
    return 0;
}
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int n, e, p;
int dist[5001];
bool isRoute[5001];
vector<pair<int, int>> v[5001];

int dijk(int from, int to){
    fill_n(dist, n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, from});
    dist[from] = 0;

    while(!pq.empty()){
        int currCost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(currCost != dist[curr]) continue;
        if(curr == to) return currCost;

        for(int i = 0; i< v[curr].size(); i++){
            int next = v[curr][i].first;
            int nextCost = v[curr][i].second;

            if(dist[next] <= currCost + nextCost) continue;

            dist[next] = currCost + nextCost;
            pq.push({dist[next], next});
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> e >>p;

    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        v[a].push_back({b, cost});
        v[b].push_back({a, cost});
    }

    int toMasan = dijk(1, n);
    int toFriend = dijk(1, p);
    int friendToMasan = dijk(p, n);

    if(toMasan == toFriend + friendToMasan) cout << "SAVE HIM\n";
    else cout << "GOOD BYE\n";

    return 0;
}

/*
5 6 3
1 2 1
1 3 1
1 4 1
2 5 1
3 5 1
4 5 1

2 1 1
1 2 1
 */
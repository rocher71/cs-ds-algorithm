#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>
using namespace std;

int n;
int parent[1001];
vector<tuple<int, int, int>> costs;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

bool isGroup(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return true;
    return false;
}

void uni(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa > pb){
        parent[a] = pa;
        parent[b] = pa;
        parent[pb] = pa;
        return;
    }
    parent[a] = pb;
    parent[b] = pb;
    parent[pa] = pb;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i< n; i++){
        int c = 0;
        for(int j = 0; j< n; j++){
            cin >> c;
            if(i <= j) continue;
            costs.push_back(make_tuple(c, i, j));
        }
    }

    sort(costs.begin(), costs.end());
    for(int i = 0; i< n; i++) parent[i] = i;

    int cnt = 0;
    long long ans = 0;
    for(int i = 0; i< costs.size(); i++){
        int cost, a, b;
        tie(cost, a, b) = costs[i];

        if(isGroup(a, b)) continue;

        uni(a, b);
        cnt++;
        ans += cost;

        if(cnt == n -1) break;
    }

    cout << ans << "\n";
    return 0;


}
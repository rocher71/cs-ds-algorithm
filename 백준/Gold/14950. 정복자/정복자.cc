#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

int n, m, t;
vector<tuple<int, int, int>> roads;
int parent[10001];

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

    cin >> n >> m >> t;
    for(int i = 0; i< m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        roads.push_back(make_tuple(c, a, b));
    }

    for(int i = 1; i<= n; i++) parent[i] = i;
    sort(roads.begin(), roads.end());

    int cnt = 0, ans = 0;
    for(int i =0 ; i< m; i++){
        int cost, a, b;
        tie(cost, a, b) = roads[i];

        if(isGroup(a, b)) continue;

        uni(a, b);

        ans += cost;
        ans += cnt * t;
        cnt++;
    }

    cout << ans  << "\n";
}
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int n, m;
vector<pair<int, long long>> graph[4001];
long long distFox[4001], distWolf[2][4001];

void bfs(){
    fill_n(distWolf[0], n + 1, LLONG_MAX);
    fill_n(distWolf[1], n + 1, LLONG_MAX);
    priority_queue<pair<long long, pair<int, bool>>, vector<pair<long long, pair<int, bool>>>, greater<pair<long long, pair<int, bool>>>> pq;
//    queue<pair<int, bool>> q; // {노드 번호, 현재 두배 속도로 갈 차례인지}
    pq.push({0, {1, true}});
//    distWolf[0][1] = 0;
//    distWolf[1][1] = 0;

    while(!pq.empty()){
        long long currCost = pq.top().first;
        int curr = pq.top().second.first;
        bool isNextTwiceSpeed = pq.top().second.second;
        pq.pop();

        if(currCost == LLONG_MAX) continue;
        if((isNextTwiceSpeed && currCost > distWolf[1][curr]) || (!isNextTwiceSpeed && currCost > distWolf[0][curr])) continue;

        for(int i = 0; i < graph[curr].size(); i++){
            int next = graph[curr][i].first;
            long long nextDist = graph[curr][i].second;

            if(next != 0 && isNextTwiceSpeed && distWolf[0][next] < currCost + nextDist) continue;
            if(next != 0 && !isNextTwiceSpeed && distWolf[1][next] < currCost + nextDist * 4) continue;

            if(isNextTwiceSpeed){
                distWolf[0][next] = currCost + nextDist;
                pq.push({distWolf[0][next], { next, !isNextTwiceSpeed}});
            }
            else{
                distWolf[1][next] = currCost + nextDist * 4;
                pq.push({distWolf[1][next], { next, !isNextTwiceSpeed}});

            }
        }
    }
}

void dijk(){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill_n(distFox, n + 1, LLONG_MAX);
    pq.push({0, 1});
    distFox[1] = 0;

    while(!pq.empty()){
        long long currDist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(int i = 0;i < graph[curr].size(); i++){
            int next = graph[curr][i].first;
            long long nextDist = graph[curr][i].second * 2;

            if(distFox[next] <= currDist + nextDist) continue;

            distFox[next] = currDist + nextDist;
            pq.push({distFox[next], next});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijk();
    bfs();

    int ans = 0;
    for(int i = 2; i<= n; i++){
//        cout << "i : " << i << ", fox : " << distFox[i] << ", distWolf[0][i] : " << distWolf[0][i] << ", distWolf[1][i] : " << distWolf[1][i] << "\n";
        if((distFox[i]< distWolf[0][i]) && (distFox[i]< distWolf[1][i])){
//            cout << i << "\n";
            ans++;
        }
    }

    cout << ans << "\n";
}
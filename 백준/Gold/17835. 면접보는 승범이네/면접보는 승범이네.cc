#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<algorithm>
#define MAX 100001
using namespace std;

long long n, m, k;
long long dist[MAX];
bool isInterview[MAX];
vector<pair<long long, long long>> graph[MAX];
vector<long long> interviews;

void dijk(int start) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        long long currCost = pq.top().first;
        long long curr = pq.top().second;
        pq.pop();

        if (currCost != dist[curr]) continue;
        
        for (int i = 0; i < graph[curr].size(); i++) {
            long long next = graph[curr][i].first;
            long long nextCost = graph[curr][i].second;

            if (dist[next] <= currCost + nextCost) continue;

            dist[next] = currCost + nextCost;
            pq.push({ dist[next], next });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        long long a, b, cost;
        cin >> a >> b >> cost;
        graph[b].push_back({ a, cost });
    }

    for (int i = 0; i < k; i++) {
        long long num;
        cin >> num;
        interviews.push_back(num);
        isInterview[num] = true;
    }

    fill_n(dist + 1, n, LLONG_MAX);
    //for (int i = 1; i <= n; i++) {
     //   if (isInterview[i]) continue;
     //   dijk(i);
   // }
    for (long long i : interviews) dijk(i);

    vector<pair<long long, long long>> ans;
    for (long long i = 1; i <= n; i++) ans.push_back({ dist[i], i });
    sort(ans.begin(), ans.end());

    long long maxDist = ans[ans.size() - 1].first;
    long long maxDistMinCityNum = ans[ans.size() - 1].second;

    for (int i = ans.size() - 2; i >= 0; i--) {
        if (maxDist != ans[i].first) break;
        maxDistMinCityNum = ans[i].second;
    }

    cout << maxDistMinCityNum << "\n" << maxDist << "\n";
    
    return 0;
}
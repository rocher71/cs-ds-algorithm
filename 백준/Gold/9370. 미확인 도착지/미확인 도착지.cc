#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
#include<unordered_set>
#include<vector>
#define MAX 2001
using namespace std;

int tc, n, m, t, s, g, h, distGH;
int startToEnd[MAX], gToEnd[MAX], hToEnd[MAX];
vector<pair<int, int>> graph[MAX];


void dijk(int start, int mode) { // 1 : start, 2 : g, 3 : h
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    if (mode == 1) startToEnd[start] = 0;
    else if (mode == 2) gToEnd[start] = 0;
    else if (mode == 3) hToEnd[start] = 0;

    pq.push({ 0, start });

    while (!pq.empty()) {
        int currCost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (mode == 1 && currCost != startToEnd[curr]) continue;
        else if (mode == 2 && currCost != gToEnd[curr]) continue;
        else if (mode == 3 && currCost != hToEnd[curr]) continue;

        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i].first;
            int nextCost = graph[curr][i].second;

            if (mode == 1 && startToEnd[next] <= currCost + nextCost) continue;
            else if (mode == 2 && gToEnd[next] <= currCost + nextCost) continue;
            else if (mode == 3 && hToEnd[next] <= currCost + nextCost) continue;

            if (mode == 1) startToEnd[next] = currCost + nextCost;
            else if (mode == 2) gToEnd[next] = currCost + nextCost;
            else if (mode == 3) hToEnd[next] = currCost + nextCost;

            pq.push({ currCost + nextCost, next });
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> t >> s >> g >> h;

        vector<int> dests;
        vector<int> ans;
        dests.clear();
        for (int i = 1; i <= n; i++) graph[i].clear();

        for (int i = 0; i < m; i++) {
            int a, b, cost;
            cin >> a >> b >> cost;
            graph[a].push_back({ b, cost });
            graph[b].push_back({ a, cost });
            if ((a == g && b == h) || (a == h && b == g)) distGH = cost;
        }

        for (int i = 0; i < t; i++) {
            int dest;
            cin >> dest;
            dests.push_back(dest);
        }

        fill_n(startToEnd, n + 1, 100000000);
        fill_n(gToEnd, n + 1, 100000000);
        fill_n(hToEnd, n + 1, 100000000);

        dijk(s, 1);

        int gToHBase = startToEnd[g] + distGH;
        int hToGBase = startToEnd[h] + distGH;

        dijk(g, 2);
        dijk(h, 3);

        for (int i : dests) {
            int shortest = startToEnd[i];
            int sGHDist = gToHBase + hToEnd[i];
            int sHGDist = hToGBase + gToEnd[i];

            if (shortest == sGHDist || shortest == sHGDist) ans.push_back(i);
        }


        sort(ans.begin(), ans.end());

        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
}
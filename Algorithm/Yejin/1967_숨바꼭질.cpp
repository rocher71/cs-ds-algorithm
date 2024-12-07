#include <iostream>
#include <queue>
using namespace std;

int n, k;
int dist[100001];
bool visit[100001];

void bfs(){
    queue<int> q;
    q.push(n);
    visit[n] = true;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i< 3; i++){
            int next = curr;
            if(i == 0) next += 1;
            else if( i == 1) next -= 1;
            else next *= 2;

            if(visit[next] || next <0 || next >= 100001) continue;

            dist[next] = dist[curr] + 1;
            visit[next] = true;
            q.push(next);
            if(next == k) return;
        }
    }
}

int main(){
    cin >> n >> k;

    bfs();

    cout << dist[k] << "\n";
}

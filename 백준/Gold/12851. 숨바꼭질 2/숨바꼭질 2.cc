#include<iostream>
#include<queue>
#define MAX 100001
using namespace std;

int n, k, minTime = -1, cnt;
int timeAt[MAX + 1];

void bfs(){
    queue<pair<int, int>> q;
    q.push({n, 0});

    while(!q.empty()){
        int curr = q.front().first;
        int currTime = q.front().second;
        q.pop();

        if(curr == k && minTime == -1){
            minTime = timeAt[curr];
            cnt++;
            continue;
        }
        if(curr == k && currTime == minTime){
            cnt++;
            continue;
        }

        if(minTime != -1 && currTime + 1 > minTime) continue;
        for(int i = 0; i< 3; i++){
            int next = curr;
            if(i == 0) next++;
            else if(i == 1) next--;
            else next *= 2;

            if(next >= MAX || curr >= MAX || curr < 0 ) continue;
            if(timeAt[next] != 0 && timeAt[next] < currTime + 1) continue;

            timeAt[next] = timeAt[curr] + 1;
            q.push({next, currTime + 1});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    bfs();

    cout << minTime << "\n" << cnt << "\n";
}

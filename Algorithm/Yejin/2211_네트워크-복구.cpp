//2211 네트워크 복구
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define INF 1e9
using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int dist[1001];
vector<int> route[1001]; //route[3] = {1, 4, 3} 이면 1->3의 최소비용 경로는 1->4->3
set<pair<int, int>> finalRoute; //정점을 두개씩 묶되 중복처리를 위해 pair자료형의 set 사용

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    route[1].push_back(1);

    while (!pq.empty()){
        auto [cost, curr] = pq.top();
        pq.pop();

        for(long unsigned int i = 0; i< graph[curr].size(); i++){
            auto [next, nextCost] = graph[curr][i];
            if(dist[next] <= cost + nextCost) continue;

            dist[next] = cost + nextCost;
            pq.push({dist[next], next});
            
            //다익스트라의 cost를 갱신할때마다 route를 저장(이전루트 + next 노드)
            route[next] = route[curr];
            route[next].push_back(next);
        }
    }
}

int main(){
    cin >>  n >>m;
    for(int i = 0; i<m; i++){
        int a, b, cost;
        cin >> a >> b>> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    fill_n(dist, n + 1, INF);

    dijkstra();

	//route 배열에 있는 정점들을 두개씩 묶어 finalRoute set에 pair로 저장
    for(int i = 1 ; i<= n; i++){
        for(long unsigned int j = 0; j < route[i].size()-1 ; j++){
            finalRoute.insert({route[i][j], route[i][j+1]});
        }
    }

    cout << finalRoute.size() <<"\n";
    //finalRoute에 있는 간선들을 출력
    for(set<pair<int, int>>::iterator it = finalRoute.begin(); it != finalRoute.end(); it++) {
        cout << it->first <<" " << it->second<<"\n";
    }
}

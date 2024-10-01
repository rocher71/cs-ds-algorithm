#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> max_pq;

int N, K, p = 0;
vector<pair<int, int>> dias;
vector<int> bags;

int maxWeight(int index){
    // 가방의 최대 무게 이하 다이아 모두 pq에 삽입
    while(p < N && dias[p].first <= bags[index]){
        max_pq.push(dias[p++].second);
    }
    if(max_pq.empty()) return 0;
    
    // 가능한 무게 중 값이 최고 인 것 return
    int maxDia = max_pq.top();
    max_pq.pop();
    return maxDia;
}

int main(){
    cin >> N >> K;
    for(int i = 0 ; i< N; i++){
        int w, v;
        cin >> w >> v;
        dias.push_back({w, v});
    }
    for(int i = 0; i < K; i++){
        int c;
        cin >> c;
        bags.push_back(c);
    }

    sort(dias.begin(), dias.end());
    sort(bags.begin(), bags.end());

    long long ans = 0;

    for(int i = 0; i<K; i++){
        ans += (long long) maxWeight(i);
    }

    cout << ans;


}

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 300001
using namespace std;

int n, k;
vector<pair<int, int>> gemInfo; // {가격, 무게}
multiset<int> bagWeight;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int m, v; // 무게, 가격
        cin >> m >> v;
        gemInfo.push_back({v, m});
    }

    for(int i = 0; i < k; i++){
        int k;
        cin >> k;
        bagWeight.insert(k);
    }

    sort(gemInfo.begin(), gemInfo.end());
//    sort(bagWeight.begin(), bagWeight.end());

    long long priceSum = 0;
    int fillCnt = 0;
    for(int i = n - 1; i >= 0; i--){
        if(fillCnt == k) break;
        int currGemPrice = gemInfo[i].first;
        int currGemWeight = gemInfo[i].second;

//        if(currGemWeight > bagWeight[k - 1]) continue;
//        int idx = lower_bound(bagWeight.begin(), bagWeight.end(), currGemWeight) - bagWeight.begin();
        auto it = bagWeight.lower_bound(currGemWeight);
        if(it == bagWeight.end()) continue;
        bagWeight.erase(it);
//        if(idx >= bagWeight.size()) continue;

//        bagWeight.erase(bagWeight.begin() + idx);
        priceSum += currGemPrice * 1L;
        fillCnt++;
    }

    cout << priceSum << "\n";
}